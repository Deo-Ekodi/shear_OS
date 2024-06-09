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
<<<<<<< HEAD
    const char* part;
    const struct path_part* next;
=======
    char* part;
    struct path_part* next;
>>>>>>> def456b (disk_streamer compplete)
};

struct path_part* pathparser_parse_path_part(struct path_part* last_part, const char** path);
void pathparser_free(struct path_root* root);
struct path_root* pathparser_parse(const char* path, const char* current_directory);





#endif