#include "bootstrap.h"

int bootstrap(){
    
    // Initialize GDT
    init_gdt();
    
    return 0;
}