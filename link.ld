/*            Original file taken from Bran's Kernel Development */
/*            tutorials: http://www.osdever.net/bkerndev/index.php. */


ENTRY(start)
SECTIONS
{
  .text 0x1000 :
  {
    code = .;
    *(.text)
    . = ALIGN(4096);
  }

  .data :
  {
     data = .;
     *(.data)
     *(.rodata)
     . = ALIGN(4096);
  }

  .bss :
  {
    bss = .;
    *(.bss)
    . = ALIGN(4096);
  }

  end = .;
} 