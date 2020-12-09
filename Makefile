# This is a variable containing all of the C++ sources.
# This will remain empty until the future
CXX_SOURCES = $(wildcard kernel/*.cpp kernel/**/*.cpp)

# We also do the same for C++ headers
CXX_HEADERS = $(wildcard kernel/*.h kernel/**/*.h)

# And we do the same for assembly files
ASM_SOURCES = $(wildcard)

# Now lets create another variable containing all of our object files
OBJECTS = ${CXX_SOURCES:.cpp=.o} # One for C++
ASMOBJECTS = ${ASM_SOURCES:.asm=.o} # One for ASM

# Now lets create a variable for all of the flags to be passed to out
# C++ compiler
CXX_FLAGS = -g -ffreestanding -Wall -Wextra -fno-exceptions -I ./

# Here we declare variables containing the command to access
# Our compiler and linker
CXX = x86_64-elf-g++
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

# First for C++ files
%.o: %.cpp ${CXX_HEADERS}
	${CXX} ${CXX_FLAGS} -c $< -o $@


# Now for assembly files
%.o: %.asm
	nasm $< -f elf64 -o $@

# Clean
clean:
	rm -rf kernel.elf image/boot/kernel.elf image.iso
	find . -type f -name '*.o' -delete