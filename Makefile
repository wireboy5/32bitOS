# This is a variable containing all of the c sources.
# This will remain empty until the future
CXX_SOURCES = $(wildcard kernel/*.c kernel/**/*.c kernel/**/**/*.c)

# We also do the same for c headers
CXX_HEADERS = $(wildcard kernel/*.h kernel/**/*.h kernel/**/**/*.h)

# And we do the same for assembly files
ASM_SOURCES = $(wildcard kernel/x86/**/*.asm)

# Now lets create another variable containing all of our object files
OBJECTS = ${CXX_SOURCES:.c=.o} # One for c
ASMOBJECTS = ${ASM_SOURCES:.asm=.o} # One for ASM

BOOTSTRAP_HEADERS = $(wildcard kernel/bootstrap/*.h kernel/bootstrap/**/*.h)
BOOTSTRAP_SOURCES = $(wildcard kernel/bootstrap/*.c kernel/bootstrap/**/*.c)
BOOTSTRAP_OBJECTS = ${BOOTSTRAP_SOURCES:.c=.o32}

# Now lets create a variable for all of the flags to be passed to out
# c compiler
CXX_FLAGS = -g -ffreestanding -Wall -Wextra -fno-exceptions -I ./

# Here we declare variables containing the command to access
# Our compiler and linker
CXX = x86_64-elf-gcc
LD = x86_64-elf-ld
CXX32 = i326-elf-gcc



# A target to build the grub image
grub: kernel.elf
	mv kernel.elf image/boot/kernel.elf
	grub-mkrescue -o image.iso image/

# A target to build the kernel.elf file
kernel.elf: kernel/asm/boot.o ${ASMOBJECTS} ${OBJECTS} 
	${LD} -o $@ -Tlink.ld $^

# Runs the kernel
run: grub
	bochs -f bochsrc.txt -q



# And here we define some rules for resolving wildcard object files
# These will go at the bottom of the file

# First for c files
%.o: %.c ${CXX_HEADERS}
	${CXX} ${CXX_FLAGS} -c $< -o $@

%.o32: %.c %{BOOTSTRAP_HEADERS}
	%{CXX32} %{CXX32_FLAGS} -C $< -o $@ -f elf64

# Now for assembly files
%.o: %.asm
	nasm $< -f elf64 -o $@


# Clean
clean:
	rm -rf kernel.elf image/boot/kernel.elf image.iso
	find . -type f -name '*.o' -delete