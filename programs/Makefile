FILES = ./build/blank.o 
INCLUDES = -I../stdlib/src

all: ${FILES}
	i686-elf-gcc -g -T ./linker.ld -o ./build/blank.elf -ffreestanding -O0 -nostdlib -fpic -g ${FILES} ./stdlib/build/stdlib.elf

./build/blank.o: ./blank/blank.c
	i686-elf-gcc $(INCLUDES) -I./blank $(FLAGS) -std=gnu99 -c ./blank/blank.c -o ./build/blank.o



clean:
# rm -r ./build/*
	rm -r ./build/*.elf
	rm -rf ${FILES}