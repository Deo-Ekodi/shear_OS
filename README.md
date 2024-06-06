# shear_OS
shear operating system

How-to-run

run build script
```./build.sh```

make should be up-to-date
```make all```

make sure gdb is installed
this will open gdb TUI
```gdb```

debug with
```target remote | qemu-system-x86_64 -hda ./bin/os.bin -S -gdb stdio```

continue debug with 
```c```

and other gdb options are valid