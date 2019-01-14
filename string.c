#include "string.h"
#include <stdint.h>

uint32_t strcopy (char *s,char *d,uint32_t count){
    int i=0;
    for (i=0;i<count;i++)
        d[i]=s[i];
}

int str_cmp (char *s,char *d){
    int i=0;
    for (i=0;s[i]!='\0';i++)
        if (s[i]!=d[i])
            return 0;
    if (s[i]=='\0' && d[i]=='\0')
        return 1;
    else 
        return 0;
}

void str_add_zero(char*src, char* dst,int pos){
    strcopy(src,dst,pos-1);
    dst[pos] = 0;
}

