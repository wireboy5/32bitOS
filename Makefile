CC = i386-elf-gcc
CXX = i386-elf-g++
LD = i386-elf-ld
CFLAGS = -ffreestanding -Wall -fno-exceptions -m32 -I ./

C_SOURCES = $(wildcard kernel/C/*.c kernel/C/**/*.c)
C_HEADERS = $(wildcard kernel/C/*.h kernel/C/**/*.h)

CXX_SOURCES = $(wildcard)
CXX_HEADERS = $(wildcard)

OBJ = ${C_SOURCES:.c=.o}
#OBJ += ${CXX_SOURCES:.cpp=.o}

kernel.elf: kernel/asm/boot.o ${OBJ}
	${LD} -Tlink.ld $^ -o $@



%.o: %.asm
	nasm $< -f elf -o $@

%.o: %.c ${C_HEADERS}
	${CC} ${CFlAGS} -c $< -o $@


clean:
	rm -f kernel.elf
	find . -type f -name '*.o' -delete
