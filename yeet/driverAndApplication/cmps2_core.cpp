#include "cmps2_core.h"
#include <cmath>

Cmps2Core::Cmps2Core(I2cCore *i2c_instance) :
    _i2c(i2c_instance),
    _x_min(32768), _x_max(-32768),
    _y_min(32768), _y_max(-32768),
    _calibration_locked(false) {}

Cmps2Core::~Cmps2Core() {}

void Cmps2Core::write_reg(uint8_t reg, uint8_t data) {
    uint8_t buf[2] = {reg, data};
    _i2c->write_transaction(DEV_ADDR, buf, 2, 0);
}

uint8_t Cmps2Core::read_reg(uint8_t reg) {
    uint8_t data;
    _i2c->write_transaction(DEV_ADDR, &reg, 1, 1);
    _i2c->read_transaction(DEV_ADDR, &data, 1, 0);
    return data;
}

void Cmps2Core::init() {
    write_reg(REG_CON1, 0x80); 
    sleep_ms(20);
    calibrate_bridge();
}

void Cmps2Core::calibrate_bridge() {
    write_reg(REG_CON0, 0x80); sleep_ms(60); 
    write_reg(REG_CON0, 0x20); sleep_ms(10); // SET
    write_reg(REG_CON0, 0x80); sleep_ms(60); 
    write_reg(REG_CON0, 0x40); sleep_ms(10); // RESET
}

int Cmps2Core::read_mag(float *mag) {
    write_reg(REG_CON0, 0x01); // Trigger
    int timeout = 50;
    while (!(read_reg(REG_STATUS) & 0x01) && --timeout > 0) sleep_ms(1);
    if (timeout <= 0) return -1;

    uint8_t start_reg = REG_XOUT_L;
    uint8_t raw[4];
    _i2c->write_transaction(DEV_ADDR, &start_reg, 1, 1);
    _i2c->read_transaction(DEV_ADDR, raw, 4, 0);

    int32_t x = (int32_t)((uint16_t)(raw[1] << 8 | raw[0])) - 32768;
    int32_t y = (int32_t)((uint16_t)(raw[3] << 8 | raw[2])) - 32768;

    if (!_calibration_locked) {
        if (x < _x_min) _x_min = x; if (x > _x_max) _x_max = x;
        if (y < _y_min) _y_min = y; if (y > _y_max) _y_max = y;
    }

    mag[0] = (float)(x - (_x_min + _x_max) / 2);
    mag[1] = (float)(y - (_y_min + _y_max) / 2);
    return 0;
}

int Cmps2Core::get_heading(float declination, bool *error) {
    float mag[2];
    if (read_mag(mag) != 0) { if (error) *error = true; return -1; }
    if (error) *error = false;

    float angle = atan2f(mag[1], mag[0]) * 180.0f / 3.14159265f;
    float final_heading = angle + declination + _user_offset;

    while (final_heading < 0)    final_heading += 360.0f;
    while (final_heading >= 360) final_heading -= 360.0f;
    return (int)final_heading;
}

const char* Cmps2Core::get_cardinal(int deg) {
    static const char* dirs[] = {"N", "NE", "E", "SE", "S", "SW", "W", "NW"};
    return dirs[((int)(deg + 22.5f) / 45) % 8];
}

void Cmps2Core::lock_calibration() { _calibration_locked = true; }
