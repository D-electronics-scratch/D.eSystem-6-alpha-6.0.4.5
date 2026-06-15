#include <stdint.h>
#include "keyboard_input.h"
#include "keyboard.h"


static inline uint8_t inb(uint16_t port) {
    uint8_t value;
    asm volatile ("inb %1, %0" : "=a"(value) : "Nd"(port));
    return value;
}

char ps2_read_key() {
    uint8_t status;
    uint8_t scancode;

    // Warten bis ein Scancode im Output Buffer liegt
    do {
        status = inb(0x64);
    } while ((status & 1) == 0);  // Bit 0 = Output Buffer Full

    scancode = inb(0x60);

    switch (scancode) {
        case 0x01: return 27;
        case 0x02: return '1';
        case 0x03: return '2';
        case 0x04: return '3';
        case 0x05: return '4';
        case 0x06: return '5';
        case 0x07: return '6';
        case 0x08: return '7';
        case 0x09: return '8';
        case 0x0A: return '9';
        case 0x0B: return '0';
        case 0x1C: return '\n';
        default:   return 0;
    }
}