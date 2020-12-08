#include "kernel.h"

extern "C" int kernel_main(){
    // We are currently using VGA in ascii text mode.
    // At memory address 0xB8000 there is a 80*24 array of characters
    // that we can place on out screen
    char* video_memory = (char*) 0xB8000;

    // Lets set the first one to X
    video_memory[0] = 'X';

    
    return 0;
}