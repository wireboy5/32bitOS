#pragma once
#include <stdint.h>
#define VIDMEM 0xB8000
#define SCREENWIDTH 80
#define SCREENHEIGHT 25



void setChar(char c, uint32_t col, uint32_t row, uint8_t color);

