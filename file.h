#ifndef __FILE_H
#define __FILE_H

void file_save (void *p,int size);
void file_open (const char fname[]);
void file_create (char name []);
void file_close ();
int file_isexist (char fname []);
void file_read (void *p,int size);

#endif