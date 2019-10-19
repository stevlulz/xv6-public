#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{

    if(argc < 4){
        printf(2,"4 arguments are required!\n");
        exit();
    }

    char* filename = argv[1];
    int offset = atoi(argv[2]);
    int whence = atoi(argv[3]);
    int fd = open(filename,O_RDWR);
    char t[10];
    printf(1,"offset : %d\n",offset);
    printf(1,"whence : %d\n",whence);
    printf(1,"fd : %d\n",fd);
    int ret = lseek(fd,offset,whence);

    printf(1,"ret : %d\n",ret);
    read(fd,t,10);
    printf(1,"Content : %s\n",t);
    printf(1,"================\n");

    exit();
}
