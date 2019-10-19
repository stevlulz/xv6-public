#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"

int
main(int argc, char *argv[])
{
    if(argc < 3){
        printf(2,"3 arguments are required!\n");
        exit();
    }
    char* prog = argv[1];
    //char* params[MAXARG] = {0};
    //params[0] = argv[1];
    char ss[512] = {0};
    char *p = ss;
    read(0,ss,128);
    while (*p != ' ')
        p++;
    //if(*p != '\n' && *p != 0)
    //    params[1] = p;

    exec(prog,&argv[1]);





    exit();
}
