#pragma once
#include <stdint.h>
#include <kernel/x86/common.h>

#define SCREENHEIGHT 25
#define SCREENWIDTH 80
#define VIDMEM 0xB8000


#define VGA_BLACK       0x0
#define VGA_BLUE        0x1
#define VGA_GREEN       0x2
#define VGA_CYAN        0x3
#define VGA_RED         0x4
#define VGA_MAGENTA     0x5
#define VGA_BROWN       0x6
#define VGA_LGREY       0x7
#define VGA_DGREY       0x8
#define VGA_LBLUE       0x9
#define VGA_LGREEN      0xA
#define VGA_LCYAN       0xB
#define VGA_LRED        0xC
#define VGA_LMAGENTA    0xD
#define VGA_YELLOW      0xE
#define VGA_WHITE       0xF 
#define VGA_DEFAULT_COLOR vgaCreateAttr(VGA_WHITE,VGA_BLACK)


void VGA_setChar(char c, uint32_t x, uint32_t y, uint8_t color);

void VGA_setCursorPosition(uint16_t x, uint16_t y);

void VGA_kprint(char* c, uint8_t color = 0x0f);

uint8_t vgaCreateAttr(uint8_t fg, uint8_t bg);