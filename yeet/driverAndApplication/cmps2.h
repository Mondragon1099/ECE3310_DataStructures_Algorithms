#ifndef _CMPS2_CORE_H_
#define _CMPS2_CORE_H_

#include "i2c_core.h"

class Cmps2Core {
public:
    Cmps2Core(I2cCore *i2c_instance);
    ~Cmps2Core();

    void init();
    void calibrate_bridge();
    void lock_calibration();
    
    // Manually set the subtraction value
    void set_manual_offset(float offset) { _user_offset = -offset; }

    int read_mag(float *mag);
    int get_heading(float declination, bool *error);
    const char* get_cardinal(int deg);

private:
    I2cCore *_i2c;
    static const uint8_t DEV_ADDR = 0x30;
    static const uint8_t REG_XOUT_L = 0x00;
    static const uint8_t REG_STATUS = 0x06;
    static const uint8_t REG_CON0   = 0x07;
    static const uint8_t REG_CON1   = 0x08;

    void write_reg(uint8_t reg, uint8_t data);
    uint8_t read_reg(uint8_t reg);

    int32_t _x_min, _x_max, _y_min, _y_max;
    float _user_offset = 0.0f; 
    bool _calibration_locked;
};

#endif
