CC = /usr/local/i386elfgcc/bin/i386-elf-gcc
CXX = i386-elf-g++
LD = /usr/local/i386elfgcc/bin/i386-elf-ld
CFLAGS = -lgcc -g -I ./ -ffreestanding

C_SOURCES = $(wildcard kernel/*.c kernel/C/*.c kernel/C/**/*.c)
C_HEADERS = $(wildcard kernel/*.h kernel/C/*.h kernel/C/**/*.h)

CXX_SOURCES = $(wildcard)
CXX_HEADERS = $(wildcard)

OBJ = ${C_SOURCES:.c=.o}
#OBJ += ${CXX_SOURCES:.cpp=.o}

grub: kernel.elf
	mv kernel.elf image/boot/kernel.elf


kernel.elf: kernel/asm/boot.o ${OBJ}
	${LD} -Tlink.ld $^ -o $@




%.o: %.asm
	nasm $< -f elf -o $@

%.o: %.c ${C_HEADERS}
	${CC} ${CFLAGS} -c $< -o $@


clean:
	rm -f kernel.elf
	find . -type f -name '*.o' -delete
