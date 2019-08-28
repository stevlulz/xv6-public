//
// Created by sidahmedlahmer on 8/28/19.
//

#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"


void
find(char* path,char* file_name){

    char buf[512];
    char *p;
    int fd;
    struct dirent de;
    struct stat st;
    if((fd = open(path, 0)) < 0){
        printf(2, "find: cannot open %s\n", path);
        return;
    }

    if(fstat(fd, &st) < 0){
        printf(2, "find: cannot stat %s\n", path);
        close(fd);
        return;
    }

    if(st.type == T_DIR){
        if(strlen(path)+1+DIRSIZ+1 > sizeof(buf)){
            printf(2,"size of path is too long");
            close(fd);
            exit();
        }

        strcpy(buf,path);
        p = buf+strlen(path);
        *p++ = '/';
        int i=0;
        while((read(fd,&de,sizeof(de))) == sizeof(de)){
            i++;

            if(de.inum == 0 || i <=2){
                continue;
            }
            //printf(1,"While()\t%s\n",de.name);
            //sleep(100);

            memmove(p,de.name,DIRSIZ);
            if(stat(buf, &st) < 0){
                printf(2, "find: cannot stat %s\n", path);
                close(fd);
                return;
            }
            switch (st.type){
                case T_FILE:
                       printf(1,"FILE\n");
                        if(strcmp((const char*)de.name,(const char*)file_name) == 0)
                            printf(1,"==========Found File : %s\n",buf);
                    break;
                case T_DIR:
                    printf(1,"DIR\n");
                    find(buf,file_name);
                    break;
            }

        }
    }

    close(fd);
}

int
main(int argc,char** argv){

    if(argc < 2){
        printf(2,"Target search must be supplied\n");
        exit();
    }

    char* file_name = argv[1];

    find(".",file_name);

    exit();
}