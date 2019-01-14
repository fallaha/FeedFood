#include "information.h"
#include "file.h"
#include "string.h"
#include <stdint.h>
#include "food.h"
#include <stdio.h>
#include <string.h>
#include "display.h"

struct information {
    char password [16];
    char nostudent [10];
    char name [20];
    char family [20];
    uint32_t money ;
    uint8_t food [FD_MAX_DAY][FD_MAX_MEAL]; /* information.food[d][m] */
};
static struct information information;

uint32_t inf_get_money (){
    return information.money;
}

void inf_set_money (uint32_t m){
    information.money = m;
    file_save(&information,sizeof(information));
}

void inf_add_money (uint32_t m){
    information.money += m;
    file_save(&information,sizeof(information));
}

void inf_dec_money (uint32_t m){
    information.money -= m;
    file_save(&information,sizeof(information));
}

void inf_set_password (char pass[]){
    strcopy(pass,information.password,sizeof(information.password));
    file_save(&information,sizeof(information));
}
char* inf_get_password (){
    return information.password;
}

void inf_set_nostudent (char nos[]){
    strcopy(nos,information.nostudent,sizeof(information.nostudent));
    file_save(&information,sizeof(information));
}

char * inf_get_nostudent (){
  return information.nostudent;
}

void inf_set_name(char name[]){
    strcopy(name,information.name,sizeof(information.name));
    file_save(&information,sizeof(information));
}
char* inf_get_name (){
    return information.name;
}

void inf_set_family (char family[]){
    strcopy(family,information.family,sizeof(information.family));
    file_save(&information,sizeof(information));
}
char* inf_get_family (){
    return information.family;
}

uint8_t inf_get_nofood (int d,int v){
    return information.food[d][v];
}

uint8_t inf_set_nofood (int d,int v,int nf){
    return information.food[d][v] = nf;
    file_save(&information,sizeof(information));
}

void inf_makeuser (char* nostudent,char* password){
    struct information inf;   
    /* set 0 to struct to avoid of any wrong */
    memset(&inf,0,sizeof(inf));
    file_create (nostudent);
    inf_set_password(password);
    inf_set_nostudent(nostudent);

}

int inf_checkpass (char pass []){
    return str_cmp(information.password,pass);

}
void inf_initialize (){
    file_read (&information,sizeof(information));
}

void inf_save (){
    file_save(&information,sizeof(information));
}