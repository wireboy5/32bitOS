#include "kernel.h"

int kernel_main(){
    char* vidmem = (char*)0xB8000;
    *vidmem = 'x';
    
    return 0;
}