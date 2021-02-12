#pragma once
#include <stdint.h>

void initPaging();



typedef struct page {
    uint8_t p: 1;
    uint8_t r: 1;
    uint8_t u: 1;
    uint8_t w: 1;
    uint8_t d: 1;
    uint8_t a: 1;
    uint8_t zero: 1;
    uint8_t s: 1;
    uint8_t g: 1;
    uint8_t avail: 3;
    uint16_t p_address: 20;
} page_t;

typedef struct page_table {
    page_t pages[512];
} page_table_t;


typedef struct page_directory {
    page_table_t* tables[512];

    uint32_t tablesPhysical[512];

    uint32_t physicalAddr;
} page_directory_t;


