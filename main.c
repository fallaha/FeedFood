#include <stdio.h>
#include "login.h"
#include "menu.h"
#include "file.h"
int main (){
	printf("Welcome to FeedFood! \n");
	user_login();
	while (1)
		show_menu();
	return 0;
}