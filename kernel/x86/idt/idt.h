#pragma once
#include <stdint.h>
#include <kernel/x86/mem/mem.h>

#define IDTSIZE 256

struct idt_entry_t {
    uint16_t baseLow;
    uint16_t selector;
    uint8_t zero = 0;
    uint8_t flags;
    uint16_t baseHigh;
};

struct idt_ptr_t {
    uint16_t limit;
    uint32_t baseAddr;
};

extern "C" void isr0();
extern "C" void isr1();
extern "C" void isr2();
extern "C" void isr3();
extern "C" void isr4();
extern "C" void isr5();
extern "C" void isr6();
extern "C" void isr7();
extern "C" void isr8();
extern "C" void isr9();
extern "C" void isr10();
extern "C" void isr11();
extern "C" void isr12();
extern "C" void isr13();
extern "C" void isr14();
extern "C" void isr15();
extern "C" void isr16();
extern "C" void isr17();
extern "C" void isr18();
extern "C" void isr19();
extern "C" void isr20();
extern "C" void isr21();
extern "C" void isr22();
extern "C" void isr23();
extern "C" void isr24();
extern "C" void isr25();
extern "C" void isr26();
extern "C" void isr27();
extern "C" void isr28();
extern "C" void isr29();
extern "C" void isr30();
extern "C" void isr31();

extern "C" void flushIDT(uint32_t ptrAddr);

void initializeIDT();
void setIdtGate(uint8_t num, uint32_t base, uint16_t selector, uint8_t flags);

