#ifndef _INFORMATION_H
#define _INFORMATION_H
#include <stdint.h>

uint32_t inf_get_money ();
void inf_set_money (uint32_t m);
void inf_add_money (uint32_t m);
void inf_set_password (char pass[]);
char* inf_get_password ();
char * inf_get_nostudent ();
void inf_set_name(char name[]);
char* inf_get_name ();
void inf_set_family (char family[]);
char* inf_get_family ();
uint8_t inf_get_nofood (int d,int v);
uint8_t inf_set_nofood (int d,int v,int nf);
void inf_makeuser (char* nostudent,char* password);
int inf_checkpass (char pass []);
void inf_initialize ();
void inf_dec_money (uint32_t m);
void inf_save ();
void inf_set_nostudent (char nos[]);
#endif /* _INFORMATION_H */