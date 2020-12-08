#include "screen.h"


void setChar(char c, uint32_t col, uint32_t row, uint8_t color){
    char* addr = (char*)(VIDMEM);
    addr[0] = 'X';
    addr[(row * 80 + col) * 2] = c;
    //addr[1] = color;
}
