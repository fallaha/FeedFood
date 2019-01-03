/* Ali Fallah (C) 97/10/12 */

#include "file.h"
#include <stdio.h>
#include "std.h"
#include "display.h"

static FILE *fp;

void file_save (void *p,int size){
    fseek(fp,0,SEEK_SET);
    fwrite (p,size,1,fp);
    fflush(fp);
}

void file_open (const char fname[]){
    fclose(fp);
    fp = fopen(fname,"r+b");

    if (!fp){
        dis_print ("Cann't open file (maybe file not exist!) : %s",fname);
        std_exit();
    }
}

void file_create (char name []){
    fp = fopen(fname,"w+b");
    if (!fp){
        dis_print ("Cann't open or create file : %s",fname);
        std_exit();
    }
}

void file_close (){
    fclose (fp);
}

int file_isexist (char fname []){
    FILE *ip;
    ip = fopen (fname,'r');
    if (!ip)
        return 0; /* File not exist */
    else 
        fclose(ip); /* first close for next use */
        return 1; /* File exist */
}

void file_read (void *p,int size){
    fseek(fp,0,SEEK_SET);
    fread (p,size,1,fp);
}