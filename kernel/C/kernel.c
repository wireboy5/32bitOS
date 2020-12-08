#include "kernel.h"

int kernel_entry(){
    char* vidMem = (char*)0xB8000;
    vidMem[0] = 'X';

    return 0;
}