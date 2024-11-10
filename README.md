

# shear_OS
shear operating system

## Install dependancies and Tools
- nasm
- [GNU cross compiler](https://wiki.osdev.org/GCC_Cross-Compiler#Installing_Dependencies)
- other dependancies [here](https://wiki.osdev.org/GCC_Cross-Compiler#Downloading_the_Source_Code)
- [QEMU](https://www.qemu.org/download/) and [GNU GDB](https://www.sourceware.org/gdb/)

1. Make sure to create a filesystem mount directory on the root folder
```bash
cd /
mkdir mnt/d
```

2. How-to-run

run build script with root permission (explicitly used in mounting filesystem only) - check [makefile](Makefile).
```./build.sh```

## Debugging Options
make sure ```gdb``` is installed
this will open gdb CLI
```gdb```

on the gdb CLI, debug with
```target remote | qemu-system-x86_64 -hda ./bin/os.bin -S -gdb stdio```

continue debug with 
```c```

and other gdb options are valid - cross check with the [.gdb_history](.gdb_history) file in the project's root directory.