CC = /usr/local/i386elfgcc/bin/i386-elf-gcc
CXX = i386-elf-g++
LD = /usr/local/i386elfgcc/bin/i386-elf-ld
CFLAGS = -lgcc -g -I ./ -ffreestanding

C_SOURCES = $(wildcard kernel/*.c)
C_HEADERS = $(wildcard kernel/*.h)

CXX_SOURCES = $(wildcard)
CXX_HEADERS = $(wildcard)

OBJ = ${C_SOURCES:.c=.o}
#OBJ += ${CXX_SOURCES:.cpp=.o}

grub: kernel.elf
	mv kernel.elf image/boot/kernel.elf
	grub-mkrescue -o image.iso image/


run: grub
	qemu-system-x86_64 -hda image.iso

kernel.elf: boot/boot.o ${OBJ}
	${LD} -Tlink.ld $^ -o $@




%.o: %.asm
	nasm $< -f elf -o $@

%.o: %.c ${C_HEADERS}
	${CC} ${CFLAGS} -c $< -o $@


clean:
	rm -f image.iso kernel.elf image/boot/kernel.elf
	find . -type f -name '*.o' -delete
