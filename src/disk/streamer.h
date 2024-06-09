#ifndef DISKSTREAMER_H
#define DISKSTREAMER_H


struct disk_stream
{
    int pos;
    struct disk* disk;
};

void diskstreamer_close(struct disk_stream* stream);
int diskstreamer_read(struct disk_stream* stream, void* out, int total);
int diskstreamer_seek(struct disk_stream* stream, int pos);
struct disk_stream* diskstreamer_new(int disk_id);





#endif