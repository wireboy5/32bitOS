#include "paging.h"



void paging() {
    // Create page directories
    for(int i = 0; i < 4; i++){
        // Create the table

        // Set the directory and mark as present
        page_dir_ptr_tab[i] = (uint64_t)&page_dir | 1
    }
}