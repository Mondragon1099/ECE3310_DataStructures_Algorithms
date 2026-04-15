#include "chu_init.h"
#include "i2c_core.h"
#include "cmps2_core.h"
#include <cstdlib>

I2cCore i2c_bus(get_slot_addr(BRIDGE_BASE, S14_CMPS2));
Cmps2Core compass(&i2c_bus);

// Helper to get a multi-digit number from UART
int get_uart_int() {
    char buf[16];
    int i = 0;
    while (true) {
        if (!uart.rx_fifo_empty()) {
            char c = uart.rx_byte();
            uart.disp(c); // Echo back to terminal
            if (c == '\r' || c == '\n') {
                buf[i] = '\0';
                return atoi(buf);
            }
            if (i < 15) buf[i++] = c;
        }
    }
}

int main() {
    uart.disp("--- MANUAL OFFSET COMPASS ---\n\r");
    compass.init();

    // 1. Magnetic mapping
    uart.disp("Rotate 360... Press any key to lock.\n\r");
    while (uart.rx_fifo_empty()) {
        compass.get_heading(11.202f, nullptr);
        sleep_ms(50);
    }
    uart.rx_byte();
    compass.lock_calibration();

    // 2. Manual Adjustment
    while (1) {
        bool err;
        int current = compass.get_heading(11.202f, &err);
        uart.disp("\rCurrent Heading: "); uart.disp(current);
        uart.disp(" deg. Press 's' to set offset or 'k' to keep.");

        if (!uart.rx_fifo_empty()) {
            char cmd = uart.rx_byte();
            if (cmd == 's') {
                uart.disp("\n\rEnter value to SUBTRACT: ");
                int val = get_uart_int();
                compass.set_manual_offset((float)val);
                uart.disp("\n\rOffset applied.\n\r");
                break; 
            }
            if (cmd == 'k') break;
        }
        sleep_ms(200);
    }

    // 3. Live mode
    while (1) {
        bool err;
        int head = compass.get_heading(11.202f, &err);
        uart.disp("Heading: "); uart.disp(head);
        uart.disp(" ["); uart.disp(compass.get_cardinal(head));
        uart.disp("]\n\r");
        sleep_ms(250);
    }
}
