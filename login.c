#include "login.h"
#include "std.h"
#include "display.h"

void user_login (){
    char nos[10];
    char pass[15];
    dis_inputs ("Enter your student number : ",nos);
    dis_inputs ("Enter your password : ",pass);

    if (file_isexist (nos)){    /* this student registered previously */
        file_open (nos);
        inf_initialize();
        for (int i=0 ; !(inf_checkpass (pass)) && i<2;i++) /* Wrong passwrd Get it again */
            dis_inputs ("password incorrect try again : ",pass);
        if (i>2){ /* wrong for 3 time */
            dis_print ("You wrong for 3 time :(");
            std_exit(); /* Close The program */
        }      
        dis_print("login Successfully!");
    }
    else {  /* this user not register */
        char c;
        dis_inputs("You didn't register! Do you want register? (y/n) : ",&c);
        if (c == 'y')
            user_register();
        else std_exit();
    }
}

void user_register (){
    char nos[10];
    char pass[15];

    dis_print("Welcome to Register Page!");
    dis_input ("Enter your student number (10 digit) : ");

    while (file_isexist (nos))
        dis_input ("This Student Number before reserved! try agin (10 digit) : ");

    dis_inputs ("Enter your password (MAX 15) : ",pass);
    inf_makeuser (nos,pass);
    dis_print("Successfully registered!");
}
