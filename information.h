#ifndef _INFORMATION_H
#define _INFORMATION_H
#include <stdint.h>

uint32_t inf_get_money ();
void inf_set_money (uint32_t m);
void inf_add_money (uint32_t m);
void inf_set_password (char pass[]);
void inf_get_password (char *pass);
void inf_get_nostudent (char *nos);
void inf_set_name(char name[]);
void inf_get_name (char *name);
void inf_set_family (char family[]);
void inf_get_family (char *family);
uint8_t inf_get_nofood (int d,int v);
uint8_t inf_set_nofood (int d,int v,int nf);

#endif /* _INFORMATION_H */