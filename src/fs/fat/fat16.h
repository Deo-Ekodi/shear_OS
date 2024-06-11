#ifndef FAT16_H
#define FAT16_H

#include <stdint.h>

#include "fs/file.h"
#include "status.h"
#include "disk/streamer.h"
#include "disk/disk.h"



void* fat16_open(struct disk* disk, struct path_part* path, FILE_MODE mode);
int fat16_resolve(struct disk* disk);
struct filesystem* fat16_init();





#endif