#include "fat16.h"
#include "status.h"
#include "string/string.h"


typedef void*(*FS_OPEN_FUNCTION)(struct disk* disk, struct path_part* path, FILE_MODE mode);
typedef int (*FS_RESOLVE_FUNCTION)(struct disk* disk);




struct filesystem fat16_fs =
{
    .resolve = fat16_resolve,
    .open = fat16_oen
};

struct filesystem* fat16_init()
{
    strcpy(fat16_fs.name, "FAT16");
    return 0;
}

int fat16_resolve(struct disk* disk)
{
    return -EIO;
}

void* fat16_oen(struct disk* disk, struct path_part* path, FILE_MODE mode)
{
    return 0;
}