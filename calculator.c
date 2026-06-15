#include "video.h"
#include "calculator.h"
#include "keyboard.h"
#include "keyboard_input.h"
#include "calculator_input.h"
#include "util.h"
//includes

void calculator_ui();
void input_calculator();
void if_else_claculator();
void version_and_kernel_version_ui();
void ui_num_1();
void ui_num2();
void ui_sum();
//modules

int op;
int num1;
int num2;
int sum;
char key = 0;
//variables

void version_and_kernel_version_ui() {
    draw_text(framebuffer, 550, 10, "D.eSystem 6.0.3 alpha", 0xFFFFFF); //render D.Kernel version
    draw_text(framebuffer, 0, 10, "kernel version: D.Kernel 0.0.2", 0xFFFFFF); //render D.eSystem version

}







void app_calculator_run() {
    int num_cmd_calculator = 0;
    clear_screen(framebuffer, 0x000000);
    print_main_ui(); //render kernel version and D.eSystem version

    calculator_ui();
    input_calculator();



}


void calculator_ui() {
    draw_text(framebuffer, 450, 135, "-----------------------------------------------", 0xFFFFFF); //render main menu from calculator
    draw_text(framebuffer, 450, 145, "|Choose an operator with one of these numbers!|", 0xFFFFFF);
    draw_text(framebuffer, 450, 155, "| [1] +                                       |", 0xFFFFFF);
    draw_text(framebuffer, 450, 165, "| [2] -                                       |", 0xFFFFFF);
    draw_text(framebuffer, 450, 175, "| [3] *                                       |", 0xFFFFFF);
    draw_text(framebuffer, 450, 185, "| [4] /                                       |", 0xFFFFFF);
    draw_text(framebuffer, 450, 195, "| [5] close                                   |", 0xFFFFFF);
    draw_text(framebuffer, 450, 205, "-----------------------------------------------", 0xFFFFFF);




}

void ui_num_1() {
    draw_text(framebuffer, 500, 135, "---------------------------------------", 0xFFFFFF);
    draw_text(framebuffer, 500, 145, "|      Type  your first number!!      |", 0xFFFFFF);
    draw_text(framebuffer, 500, 155, "---------------------------------------", 0xFFFFFF);
    
}

void ui_num2() {
    draw_text(framebuffer, 500, 135, "---------------------------------------", 0xFFFFFF);
    draw_text(framebuffer, 500, 145, "|     Type  your seccond number!!     |", 0xFFFFFF);
    draw_text(framebuffer, 500, 155, "---------------------------------------", 0xFFFFFF);

}

void ui_sum() {
    draw_text(framebuffer, 500, 135, "-----------------------------------------", 0xFFFFFF);
    draw_text(framebuffer, 500, 145, "|            D.Calculator               |", 0xFFFFFF);
    draw_text(framebuffer, 500, 155, "-----------------------------------------", 0xFFFFFF);
    draw_text(framebuffer, 500, 165, "| sum:                                  |", 0xFFFFFF);
    draw_text(framebuffer, 500, 175, "-----------------------------------------", 0xFFFFFF);
    draw_text(framebuffer, 500, 185, "| [1] continue                          |", 0xFFFFFF);
    draw_text(framebuffer, 500, 195, "-----------------------------------------", 0xFFFFFF);
    print_main_ui();

}


void input_calculator() {
 
    op = calculator_read_int(450, 230);
    if_else_claculator();


}


void if_else_claculator() {
    if (op == 1) {
        ;
        clear_screen(framebuffer, 0x000000);
        print_main_ui();
        ui_num_1();
        num1 = calculator_read_int(450, 230);
        clear_screen(framebuffer, 0x000000);
        print_main_ui();
        ui_num2();
        num2 = calculator_read_int(450, 230);
        sum = num1 + num2;
        clear_screen(framebuffer, 0x000000);
        
        char buf[32];
        int_to_string(sum, buf);
        draw_text(framebuffer, 550, 165, buf, 0xFFFFFF);
        
        ui_sum();

        while (key == 0) {
            key = input_read_ascii();
        }
        if (key == '1') {
            key = 0;
            clear_screen(framebuffer, 0x000000);
            app_calculator_run();
        }

        

    } else if (op == 2) {
        clear_screen(framebuffer, 0x000000);
        print_main_ui();
        ui_num_1();
        num1 = calculator_read_int(450, 230);
        clear_screen(framebuffer, 0x000000);
        print_main_ui();
        ui_num2();
        num2 = calculator_read_int(450, 230);
        sum = num1 - num2;
        clear_screen(framebuffer, 0x000000);

        char buf[32];
        int_to_string(sum, buf);
        draw_text(framebuffer, 550, 165, buf, 0xFFFFFF);
        ui_sum();
        while (key == 0) {
            key = input_read_ascii();
        }
        if (key == '1') {
            key = 0;
            clear_screen(framebuffer, 0x000000);
            app_calculator_run();


        }
        
    } else if (op == 3) {
        clear_screen(framebuffer, 0x000000);
        print_main_ui();
        ui_num_1();
        num1 = calculator_read_int(450, 230);
        clear_screen(framebuffer, 0x000000);
        print_main_ui();
        ui_num2();
        num2 = calculator_read_int(450, 230);
        sum = num1 * num2;
        clear_screen(framebuffer, 0x000000);
        char buf[32];
        int_to_string(sum, buf);
        draw_text(framebuffer, 550, 165, buf, 0xFFFFFF);
        ui_sum();
        while (key == 0) {
            key = input_read_ascii();
        }
        if (key == '1') {
            key = 0;
            clear_screen(framebuffer, 0x000000);
            app_calculator_run();

        }



    } else if (op == 4) {


        clear_screen(framebuffer, 0x000000);
        print_main_ui();
        ui_num_1();
        num1 = calculator_read_int(450, 230);
        clear_screen(framebuffer, 0x000000);
        print_main_ui();

        ui_num2();
        num2 = calculator_read_int(450, 230);
        if (num2 == 0) {
            sum = 0;
            clear_screen(framebuffer, 0x000000);
            char buf[32];
            int_to_string(sum, buf);
            draw_text(framebuffer, 550, 165, buf, 0xFFFFFF);
            ui_sum();
            while (key == 0) {
                key = input_read_ascii();

            }

            if (key == '1') {
                key = 0;
                clear_screen(framebuffer, 0x000000);
                app_calculator_run();

            }
        }
        sum = num1 / num2;
        clear_screen(framebuffer, 0x000000);
        char buf[32];
        int_to_string(sum, buf);
        draw_text(framebuffer, 550, 165, buf, 0xFFFFFF);
        ui_sum();
        while (key == 0) {
            key = input_read_ascii();

        }
        if (key == '1') {
            key = 0;
            clear_screen(framebuffer, 0x000000);
            app_calculator_run();

        } 


    } else if (op == 5) {
        clear_screen(framebuffer, 0x000000);
        ui_desktop();
        return;
    } else {
        app_calculator_run();
    }
}