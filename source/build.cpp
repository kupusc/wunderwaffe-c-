#include <sys/inotify.h>
#include <unistd.h>
#include <string.h>

bool work = true;

void stop()
{
    work = false;
}

void watch()
{
    int inotify = inotify_init();
    if(inotify == -1) throw "inotify_init exit -1";

    int watch = inotify_add_watch(inotify, "./", IN_CLOSE_WRITE|IN_DELETE);
    if (watch == -1) throw "inotify_add_watch error";

    size_t filname_len = 1024;
    char *filename = new char[filname_len];
    ssize_t read_len = 0;

    while(work)
    {
        read_len = read(watch, filename, filname_len);
        if(read_len == -1) throw "read error";
    }
}
