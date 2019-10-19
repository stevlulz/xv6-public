//
// Created by sidahmedlahmer on 10/9/19.
//


#include "types.h"
#include "defs.h"
#include "param.h"
#include "traps.h"
#include "spinlock.h"
#include "sleeplock.h"
#include "fs.h"
#include "file.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "x86.h"


int drvmemread(struct inode *ip, char *dst, int n,unsigned int offset){

    short min = ip->minor;
    switch (min){
        default:
            return -1;
        case 0:
            //dev/null
            return 0;
        case 1:
            //dev/zero
            memset((void*)dst,0,n);
            return n;
        case 2:
            if(!(offset >= EXTMEM && offset+n <= PHYSTOP))
                return -1;//error
            memmove(dst,P2V(offset),(unsigned int)n);
            return n;

    }

}

int drvmemwrite(struct inode *ip, char *buf, int n,unsigned int offset){

    return 0;
}

void drvmeminit(void){

    devsw[DRVMEM].read = drvmemread;
    devsw[DRVMEM].write = drvmemwrite;

}