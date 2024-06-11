#ifndef FAT16_H
#define FAT16_H

#include <stdint.h>

#include "fs/file.h"
#include "status.h"
#include "disk/streamer.h"
#include "disk/disk.h"

#define SHEAROS_FAT16_SIGNATURE         0x29
#define SHEAROS_FAT16_FAT_ENTRY_SIZE    0x02
#define SHEAROS_FAT16_BAD_SECTOR        0xFF7
#define SHEAROS_FAT16_UNSIGNED          0x00

// fat directories attributes bitmask
#define FAT_FILE_READ_ONLY      0x01
#define FAT_FILE_HIDDEN         0x02
#define FAT_FILE_SYSTEM         0x04
#define FAT_FILE_VOLUME_LABEL   0x08
#define FAT_FILE_SUBDIRECTORY   0x10
#define FAT_FILE_ARCHIVED       0x20
#define FAT_FILE_DEVICE         0x40
#define FAT_FILE_RESERVED       0x80

typedef unsigned int FAT_ITEM_TYPE;
#define FAT_ITEM_TYPE_DIRECTORY 0
#define FAT_ITEM_TYPE_FILE      1







void* fat16_open(struct disk* disk, struct path_part* path, FILE_MODE mode);
int fat16_resolve(struct disk* disk);
struct filesystem* fat16_init();





#endif