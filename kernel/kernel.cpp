#include "kernel.h"

extern "C" int kernel_main(){
    VGA_kprint("abcd\n");
    
    return 0;
}