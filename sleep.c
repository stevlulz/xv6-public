#include "types.h"
#include "stat.h"
#include "user.h"


int
main(int argc, char *argv[])
{

    if(argc <= 1){
        printf(2,"sleeping time must be supplied\n");
        exit();
    }

    int t =  atoi(argv[1]);
    if(t >= 0)
     sleep(t);
    else
        printf(2,"you must supply positive number");
    exit();
}
