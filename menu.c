#include "menu.h"
#include "display.h"
#include <stdint.h>

void show_menu (){
    int c;

    dis_print("1. This Week reserved food");
    dis_print("2. reserving food");
    dis_print("3. Show detail");
    dis_print("4. Increase credit");
    dis_print("5. change password");
    dis_print("6. exit");

    dis_inputi ("",c);

    switch(c){
        case 1:
            show_reserved_food();
            break;
        case 2:
            reserve_food();
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
            exit(0);
            break;            
    }
}

void show_detail (){
    char str [20];

    inf_get_name(str);
    dis_print("Your Name : ",str);

    inf_get_family(str);
    dis_print("Your Family : ",str);
    
    inf_get_nostudent(str);
    dis_print("Student Number : ",str);

    dis_print("Credit : %d",inf_get_money());
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