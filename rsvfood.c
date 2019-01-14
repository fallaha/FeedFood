#include "rsvfood.h"
#include "display.h"
#include "information.h"
#include "food.h"

/* it's Biggest Function But not hard to Undrestanding */
int rsv_food (){
   int d; /* day */
    int m; /* meal */
    int f; /* food type */
    int i; /* Counter */

    dis_print ("--------------Reserving Food--------------\n");

    /*  Get number of Day */
    dis_print("\n   ======================\n");
    dis_print("  /  N\t|    Day\t/\n");
    dis_print("  ======================\n");

    dis_print(" |  00\t| Saturday\t|\n");
    dis_print("  ----------------------\n");
    dis_print(" |  01\t| Sunday \t|\n");
    dis_print("  ----------------------\n");
    dis_print(" |  02\t| Monday\t|\n");
    dis_print("  ----------------------\n");
    dis_print(" |  03\t| Tuesday\t|\n");
    dis_print("  ----------------------\n");
    dis_print(" |  04\t| Wednesday\t|\n");
    dis_print("  ----------------------\n");
    dis_print(" |  05\t| Thursday\t|\n");
    dis_print("  ----------------------\n");
    dis_print(" |  06\t| Friday\t|\n");
    dis_print("  ----------------------\n");

    dis_inputi("Enter N of Food > ",d);

    while (!(d>= 0 && d<=6)){
        dis_inputi("Wrong Input. Try again! \nEnter N of Food > ",d);
    }


    /*  Get number of Meal */

    dis_print("\n   ======================\n");
    dis_print("  /  N\t:    Meal\t/\n");
    dis_print("  ======================\n");

    dis_print(" | 00\t| Breakfast\t|\n");
    dis_print("  ----------------------\n");
    dis_print(" | 01\t| Lunch \t|\n");
    dis_print("  ----------------------\n");
    dis_print(" | 02\t| Dinner\t|\n");
    dis_print("  ----------------------\n");
    dis_inputi("Enter N of Meal > ",m);
    while (!(m>= 0 && m<=2)){
        dis_inputi("Wrong Input. Try again! \nEnter N of Meal > ",m);
    }

    if (!inf_get_nofood(d,m)){
        int yn;
        dis_inputi("You reserved this meal previously! do you want to continue?(1:Yes , 0:No) > ",yn);
        if (!yn)
            return 0;

        inf_add_money(food_get_price(inf_get_nofood(d,m))); /* Add money to user Account */
        inf_set_nofood(d,m,0); /* Set Null to food Name */ 
    }

     /*  Get number of Food */

    dis_print("\n   ======================================== \n");
    dis_print("  /  N\t|    FoodName\t |     Price\t  /\n");
    dis_print("   ====================================== \n");
    int id; /* identifire of food */

    for (i=0; id=food_get_id (d,m,i); i++){
        dis_print(" |  %.2d\t| %s\t |    %0.d\t  |\n",i,food_get_name(id),food_get_price(id));
        dis_print("   -------------------------------------- \n");
    }
    dis_inputi("Enter N of Food > ",f);
        while (!(f>= 0 && f<=2)){
        dis_inputi("Wrong Input. Try again! \nEnter N of Food > ",f);
    }
    id=food_get_id (d,m,f); /* Set id of chosen Food */

    /* Now We have day and meal and food type so ... */

    if (food_get_price(id)>inf_get_money()){ /* Low Money */
        dis_print("Low Money! Please Charge!\n");
        return 0;
    }

    inf_dec_money(food_get_price(id)); /* Decrease price of food from user account */
    inf_set_nofood(d,m,id);
    dis_print("Reserved Successfully!\n");
    return 1;
}

void rsv_show_food (){
    int d,m;
    dis_print("   ================> Your Food Reserved List <====================\n");
    dis_print("   ==============================================================\n");
    dis_print("  |     Day\t |   Sobhaneh\t |    Naahar\t |    Sham    \t |\n");
    dis_print("   ==============================================================\n");
    for (d=0;d<food_get_max_day();d++){
        dis_print("  |  %s \t |",food_get_day_name(d));
        for(m=0;m<food_get_max_meal();m++)
              dis_print ("  %s\t |",food_get_name(inf_get_nofood(d,m)));
       dis_print("\n   ==============================================================\n");
    }
}