#ifndef DISK_H
#define DISK_H

typedef unsigned int SHEAROS_DISK_TYPE;

#define SHEAROS_DISK_TYPE_REAL      0

struct disk
{
    SHEAROS_DISK_TYPE type;
    int sector_size;
};

void disk_search_and_init();
struct disk* disk_get(int index);
int disk_read_block(struct disk* idisk, unsigned int lba, int total, void* buf);



#endif