#ifndef CONFIG_H
#define CONFIG_H

#define SHEAROS_TOTAL_INTERRUPTS 512
#define KERNEL_CODE_SELECTOR 0x08
#define KERNEL_DATA_SELECTOR 0x10


/**
 * 1024 * 1024 = 10485676 == 1mb
 * 10485676 * 100 = 100mb
 * 100mb / 4096 bytes(block size) = 25600 entries
 */

#define SHEAROS_HEAP_SIZE_BYTES         104857600
#define SHEAROS_HEAP_BLOCK_SIZE         4096
#define SHEAROS_HEAP_ADDRESS            0x01000000
#define SHEAROS_HEAP_TABLE_ADDRESS       0x00007E00
#define SHEAROS_SECTOR_SIZE             512


#endif