#ifndef _STRING_H
#define _STRING_H
#include <stdint.h>
/* Function */
uint32_t strcopy (char *s,char *d,uint32_t count);
int str_cmp (char *s,char *d);
void str_add_zero(char*src, char* dst,int pos);
#endif /* _STRING_H */