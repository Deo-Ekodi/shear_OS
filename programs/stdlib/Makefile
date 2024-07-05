FILES = ./build/start.o ./build/shearos.o
INCLUDES = 

all: ${FILES}
	i686-elf-ld -m elf_i386 -relocatable ${FILES} -o ./build/stdlib.elf

./build/start.o: ./src/start.asm
	nasm -f elf ./src/start.asm -o ./build/start.o

./build/shearos.o: ./src/shearos.asm
	nasm -f elf ./src/shearos.asm -o ./build/shearos.o



clean:
	rm -rf ${FILES}
	rm ./build/*.elf
