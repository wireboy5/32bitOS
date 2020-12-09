# This is a variable containing all of the c sources.
# This will remain empty until the future
C_SOURCES = $(wildcard kernel/*.c kernel/**/*.c)

# We also do the same for c headers
C_HEADERS = $(wildcard kernel/*.h kernel/**/*.h)

# And we do the same for assembly files
ASM_SOURCES = $(wildcard)

# Now lets create another variable containing all of our object files
OBJECTS = ${C_SOURCES:.c=.o} # One for c
ASMOBJECTS = ${ASM_SOURCES:.asm=.o} # One for ASM

# Now lets create a variable for all of the flags to be passed to out
# c compiler
C_FLAGS = -g -ffreestanding -Wall -Wextra -fno-exceptions -I ./

# Here we declare variables containing the command to access
# Our compiler and linker
C = x86_64-elf-gcc
LD = x86_64-elf-ld



# A target to build the grub image
grub: kernel.elf
	mv kernel.elf image/boot/kernel.elf
	grub-mkrescue -o image.iso image/

# A target to build the kernel.elf file
kernel.elf: kernel/asm/boot.o ${OBJECTS}
	${LD} -o $@ -Tlink.ld $^

# Runs the kernel
run: grub
	qemu-system-x86_64 -hda image.iso -machine type=pc-q35-2.10



# And here we define some rules for resolving wildcard object files
# These will go at the bottom of the file

# First for c files
%.o: %.c ${C_HEADERS}
	${C} ${C_FLAGS} -c $< -o $@


# Now for assembly files
%.o: %.asm
	nasm $< -f elf64 -o $@

# Clean
clean:
	rm -rf kernel.elf image/boot/kernel.elf image.iso
	find . -type f -name '*.o' -delete