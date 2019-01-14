#include "login.h"
#include "std.h"
#include "display.h"
#include "file.h"
#include "information.h"

void user_login (){
    char nos[10];
    char pass[15];
    int i=0;
    dis_inputs ("Enter your student number : ",nos);
    dis_inputs ("Enter your password : ",pass);

    if (file_isexist (nos)){    /* this student registered previously */
        file_open (nos);
        inf_initialize();
        for (i=0 ; inf_checkpass (pass)==0 && i<2;i++){ /* Wrong passwrd Get it again */
            dis_inputs ("password incorrect try again : ",pass);
        }
        if (i>2){ /* wrong for 3 time */
            dis_print ("You wrong for 3 time :(\n");
            std_exit(); /* Close The program */
        }      
        dis_print("login Successfully!\n");
        dis_print ("Welecom %s Dear!\n",inf_get_name());
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
    char nos[11];
    char pass[15];
    char name [20];
    char last_name[20];
    dis_print("Welcome to Register Page!");
    dis_inputs ("Enter your student number (10 digit) : ",nos);

    while (file_isexist (nos)){
        dis_inputs ("This Student Number before reserved! try agin (10 digit) : ",nos);
    }
    dis_print("Login username = %s \n",nos);
    dis_inputs ("Enter your password (MAX 15) : ",pass);
    nos[10]=0;
    inf_makeuser (nos,pass);
    /* Get Full Name of Student */
    dis_inputs ("what's your First name : ",name);
    dis_inputs ("what's your Last  name : ",last_name);

    inf_set_name(name);
    inf_set_family(last_name);

    dis_print("Successfully registered!\n");
}
