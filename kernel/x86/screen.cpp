#include "screen.h"

uint32_t getCursorPosition();
uint32_t getOffset(uint32_t x, uint32_t y);
uint32_t getOffsetRow(uint32_t offset);
uint32_t getOffsetCol(uint32_t offset);

uint32_t cursorPos = 0;



void VGA_setChar(char c, uint32_t x, uint32_t y, uint8_t attr) {
    
    uint32_t position = getOffset(x,y);
    if(position > (SCREENHEIGHT * SCREENWIDTH * 2)){
        position = SCREENWIDTH * SCREENHEIGHT * 2;
    }
    char *vidmem = (char*) VIDMEM;
    vidmem[position + 1] = c;
    vidmem[position + 2] = attr;
}


void VGA_setCursorPosition(uint16_t x, uint16_t y){
    uint32_t offset = y * 80 + x;
    outb(0x3D4, 14);
    outb(0x3D5, offset >> 8);
    outb(0x3D4, 15);
    outb(0x3D5, offset);
}

void VGA_printChar(char c, uint8_t color){
    
    uint32_t cursPos = getCursorPosition();
    uint32_t cursX = getOffsetCol(cursPos);
    uint32_t cursY = getOffsetRow(cursPos);
    if(c == 0x08){
        cursX--;
    } else if (c == '\n')
    {
        cursX = 0;
        cursY++;
    } else if (c == '\r'){
        cursX = 0;
    } else {
        VGA_setChar(c,cursX,cursY,color);
        cursX++;
    }
    VGA_setCursorPosition(cursX,cursY);
}

void VGA_kprint(char* c, uint8_t color)
{
    
    while(*c){
        VGA_printChar(*c, color);
        
        c++;
    }
}


uint8_t vgaCreateAttr(uint8_t fg, uint8_t bg){
    return (bg << 4) | (fg);
}


uint32_t getCursorPosition(){
    outb(0x3D4, 14);
    uint32_t offset = inb(0x3D5);
    offset = offset << 8;
    outb(0x3D4, 15);
    offset += inb(0x3D5);
    return 2 * offset;
}


uint32_t getOffset(uint32_t x, uint32_t y){
    return ((y * SCREENWIDTH + x) * 2);
}
uint32_t getOffsetRow(uint32_t offset){
    return offset / (SCREENWIDTH * 2);
}
uint32_t getOffsetCol(uint32_t offset){
    return (offset - (getOffsetRow(offset) * SCREENWIDTH * 2))/2;
}