#include "keyboard.h"
#include "keyboard_input.h"
#include "video.h"

int calculator_read_int(int x, int y) {
    input_reset();

    draw_text(framebuffer, x, y, "Enter number: ", 0xFFFFFF);
    int cursor_x = x + 120;

    while (1) {
        char c = input_read_ascii();
        if (c == 0) continue;

        if (c == '\n') break;

        char str[2] = {c, 0};
        draw_text(framebuffer, cursor_x, y, str, 0xFFFFFF);
        cursor_x += 8;

        input_add_char(c);
    }

    return input_get_int();
}