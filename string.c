#include "string.h"

uint32_t strcopy (char *s,char *d,uint32_t count){
    int i=0;
    for (i=0;i<count;i++)
        s[i]=d[i];
}