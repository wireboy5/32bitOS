#include "gdt.h"
uint64_t create_gdt_entry(
    uint32_t base,
    uint32_t limit,
    uint16_t flag);
uint64_t create_gdt_entry(
    uint32_t base,
    uint32_t limit,
    uint16_t flag){

    uint64_t descriptor;

    // High half 32 half of the descriptor
    descriptor  = limit         & 0x000F0000;
    descriptor |= (flag << 8)   & 0x00F0FF00;
    descriptor |= (base >> 16)  & 0x000000FF;
    descriptor |= base          & 0xFF000000;

    // Shift to the low part
    descriptor <<= 32;

    // Low 32 bit segment
    descriptor |= base   << 16;
    descriptor |= limit   & 0x0000FFFF;

    // Return the descriptor
    return descriptor;  
}

uint64_t gdt[5];
gdt_ptr_t gdt_ptr;
extern void gdt_flush(uint32_t addr);
void init_gdt(){
    // Create the descriptors
    gdt[0] = create_gdt_entry(0, 0, 0);
    gdt[1] = create_gdt_entry(0, 0xFFFFFFFF, (GDT_CODE_PL0));
    gdt[2] = create_gdt_entry(0, 0xFFFFFFFF, (GDT_DATA_PL0));
    gdt[3] = create_gdt_entry(0, 0xFFFFFFFF, (GDT_CODE_PL3));
    gdt[4] = create_gdt_entry(0, 0xFFFFFFFF, (GDT_DATA_PL3));
    
    // Create a GDT pointer
    gdt_ptr.limit = (sizeof(uint64_t)*5)-1;
    gdt_ptr.base = (size_t)&gdt;

    // Flush the GDT
    gdt_flush(&gdt_ptr);

    return;
}