#include "menu.h"
#include "display.h"
#include <stdint.h>
#include "rsvfood.h"
#include <stdlib.h>
#include "information.h"
#include "file.h"

void inc_credit() ;
void change_pass ();
void show_detail ();


void show_menu (){
    int c;

    dis_print("1. This Week reserved food\n");
    dis_print("2. reserving food\n");
    dis_print("3. Show detail\n");
    dis_print("4. Increase credit\n");
    dis_print("5. change password\n");
    dis_print("6. exit\n");

    dis_inputi ("select > ",c);

    switch(c){
        case 1:
            rsv_show_food();
            break;
        case 2:
            rsv_food();
            break;
        case 3:
            show_detail();
            break;
        case 4:
            inc_credit();
            break;
        case 5:
            change_pass();
            break;
        case 6:
            inf_save();
            exit(0);
            break;            
    }
}

void show_detail (){
    dis_print(" *** Detail ***\n");
    dis_print("Your Name          :\t %s\n",inf_get_name());
    dis_print("Your Family        :\t %s\n",inf_get_family());
    dis_print("StudentNumber      :\t %.10s\n",inf_get_nostudent());
    dis_print("Credit UserAccount :\t %d (rls)\n",inf_get_money());
}

void change_pass (){
    char password [16];
    dis_inputs ("enter new password [MAX 15] : ",password);
    inf_set_password(password);
}
void inc_credit() {
    uint32_t money;
    dis_inputi ("enter amount of money : ",money);
    inf_add_money(money);
}