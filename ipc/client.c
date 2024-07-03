#include "common.h"

int main(int argc, char **argv)
{
    struct Shared *ptr;
    struct stat buf;
    sem_t *mutex;
    int fd;
    int nloop;
    int i;

    fd = shm_open(SHM_FILE, O_RDWR, 0);
    fstat(fd, &buf);
    ptr = mmap(NULL, buf.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);

    mutex = sem_open(SEM_PATH, 0);
    nloop = atoi(argv[1]);

    for (i = 0; i < nloop; i++)
    {
        sem_wait(mutex);
        printf("pid %d: %d\n", getpid(), ptr->count++);
        sem_post(mutex);
    }

    return 0;
}
