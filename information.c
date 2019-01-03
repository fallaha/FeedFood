#include "information.h"
#include "file.h"
#include "string.h"
#include <stdint.h>

struct dayfood {
    uint8_t food [3];
}
struct weekfood{
    struct dayfood df [7];
}
struct information {
    char password [15];
    char nostudent [10];
    char name [20];
    char family [20];
    uint32_t money = 0;
    struct weekfood wf; /* information.wf.df[i].food[j] */
};
static struct information information;

uint32_t inf_get_money (){
    return information.money;
}

void inf_set_money (uint32_t m){
    information.money = m;
    file_save();
}

void inf_add_money (uint32_t m){
    information.money += m;
    file_save();
}

void inf_set_password (char pass[]){
    strcopy(pass,&information.password,sizeof(information.password));
    file_save();
}
void inf_get_password (char *pass){
    strcopy(&information.password,pass,sizeof(information.password));
}

void inf_get_nostudent (char *nos){
    strcopy(&information.nostudent,nos,sizeof(information.nostudent));
}

void inf_set_name(char name[]){
    strcopy(name,&information.name,sizeof(information.name));
    file_save();
}
void inf_get_name (char *name){
    strcopy(&information.name,name,sizeof(information.name));
}

void inf_set_family (char family[]){
    strcopy(family,&information.family,sizeof(information.family));
    file_save();
}
void inf_get_family (char *family){
    strcopy(&information.family,family,sizeof(information.family));
}

uint8_t inf_get_nofood (int d,int v){
    return information.weekfood.df[d].food[v];
}

uint8_t inf_set_nofood (int d,int v,int nf){
    return information.weekfood.df[d].food[v] = nf;
}