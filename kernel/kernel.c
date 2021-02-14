#include "kernel.h"

/*
    Screen Colors (For Reference)
        0 : black
        1 : blue
        2 : green
        3 : cyan
        4 : red
        5 : magenta
        6 : brown
        7 : light grey
        8 : dark grey
        9 : light blue
        A : light green
        B : light cyan
        C : light red
        D : light magneta
        E : light brown
        F : white. 
*/

int kernel_main(){
    
    char* vidmem = (char*)0xb8000;
    vidmem[3] = 'K';

    

	return 0;

}


