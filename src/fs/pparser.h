#ifndef PPARSER_H
#define PPARSER_H

#define SHEAROS_MAX_PATH 108

struct path_root
{
    int drive_no;
    struct path_part* first;
};

struct path_part
{
    const char* part;
    const path_part* next;
};

#endif