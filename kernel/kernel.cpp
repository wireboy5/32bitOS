#include "kernel.h"

extern "C" int kernel_main(){
    
    setChar('F',0,0,0xFf);

    
    return 0;
}