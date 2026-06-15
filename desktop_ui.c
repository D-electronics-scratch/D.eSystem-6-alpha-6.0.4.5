#include "video.h"

void ui_desktop();



void ui_desktop() {
    clear_screen(framebuffer, 0x202020);
    draw_text(framebuffer, 500, 50, "--------------------------------", 0xFFFFFF);
    draw_text(framebuffer, 500, 60, "| [Esc] Shutdown               |", 0xFFFFFF);
    draw_text(framebuffer, 500, 70, "| [2] calculator               |", 0xFFFFFF);
    draw_text(framebuffer, 500, 80, "| [3] clock                    |", 0xFFFFFF);
    draw_text(framebuffer, 500, 90, "| [4] info                     |", 0xFFFFFF);
    draw_text(framebuffer, 500, 100, "| [5] calendar                 |", 0xFFFFFF);
    draw_text(framebuffer, 500, 110, "--------------------------------", 0xFFFFFF);
    print_main_ui();
    

}
    