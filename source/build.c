#include <sys/inotify.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int work = 100;

void stop()
{
    work = 0;
}

void watch(char const* path)
{
    int inotify = inotify_init();
    if(inotify == -1) return;
    int watch = inotify_add_watch(inotify, path, IN_CLOSE_WRITE|IN_DELETE);
    if (watch == -1) return;

    size_t filname_len = 65536;
    char filename[filname_len];
    ssize_t read_len = 0;

    while(work--)
    {
        read_len = read(watch, &filename, filname_len);
        /* if(read_len == -1) exit(-1);*/
        printf("changed file: %s", filename);
    }
}
