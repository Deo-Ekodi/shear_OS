#ifndef FAT16_H
#define FAT16_H

#include "fs/file.h"


void* fat16_open(struct disk* disk, struct path_part* path, FILE_MODE mode);
int fat16_resolve(struct disk* disk);
struct filesystem* fat16_init();





#endif