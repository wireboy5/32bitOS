mbootmagic equ 0x1BADB002
mbootflags equ 1 | 2
mbootcheck equ -(mbootmagic + mbootflags)

; Extern Addresses of sectionsn
[extern code]
[extern bss]
[extern end]


[extern multiboot]

multiboot:
    dd mbootmagic   ; Multiboot Magic
    dd mbootflags   ; Multiboot Flags
    dd mbootcheck   ; Multiboot Checksum

    dd multiboot    ; This section

    ; Code, bss, and end sections
    dd code
    dd bss
    dd end

    ; The start of our kernel
    dd start




; Make sure we can access start
[global start]

; And that we can access the kernel's entry
[extern kernel_entry]

start:
    cli
    call kernel_entry
    jmp $