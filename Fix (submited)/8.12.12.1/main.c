#include "lib/lib.h"
short int kondisi;

int main(void) {
    kondisi = Guide();
    while (kondisi != 0){
        if (kondisi == 1 || kondisi == 2){
            kondisi = Head();
            while (kondisi != 0){
                switch (kondisi){
                case 1: kondisi = Input();
                    break;
                case 2: kondisi = Output();
                    break;
                case 3: kondisi = ViewData();
                    break;
                case 4: kondisi = Setting();
                    break;
                case 9: kondisi = Head();
                    break;
                }
            }
            kondisi = Guide();
        }
        else if (kondisi == 9){
            kondisi = Guide();
        }
    }
    puts("\nBye\n");
    return 0;
}