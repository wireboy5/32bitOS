#include "isr.h"

extern "C" void isr_handler(registers_t regs){
    printf("Recieved interrupt: %x\n",regs.intNo);
}