#include "screen.h"

void x86C_setChar(char* chr, uint32_t row, uint32_t col){
    char* vidMem = (char*)0xB8000;
    
    // Make sure row * col is smaller than vidMemSize
    if(row*col >= vidMemSize){
        vidMem[vidMemSize*2] = chr;
        return;
    }
    uint32_t addr = row * col * 2;
    vidMem[row * col * 2] = chr;

}