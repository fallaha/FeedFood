#include "food.h"
#include <stdint.h>
#include "information.h"

/* Important note : The Food Number start from 1 (not 0) */
// add new comment for git test
static char food_name_list[FD_MAX_FOOD][FD_MAX_NAME]={
    "     -     ",    /* None */
    /*    BreakFast           */
    "Kare Asal",        /* 01 */                    
    "TokhmeMorgh",      /* 02 */
    "Adasi   ",         /* 03 */
    "Halva   ",         /* 04 */
    "Omlet   ",         /* 05 */
    "KareMorabba",      /* 06 */
    "Sheer   ",         /* 07 */
    "KhameAsali",       /* 08 */
    "Panir   ",         /* 09 */
    /*     Lunch & Dinner     */
    "Kabaab  ",         /* 10 */
    "Morgh   ",         /* 11 */
    "Gheyme  ",         /* 12 */
    "Jooje   ",         /* 13 */
    "GhormeSabzi",      /* 14 */
    "AdasPolo",         /* 15 */
    "Meygoo  ",         /* 16 */
    "KuKuSib ",         /* 17 */
    "LubiaPulu",        /* 18 */
    "Tone Mahey",       /* 19 */
    "Falafel ",         /* 20 */
    "Makaroni",         /* 21 */
    "ShevidPulu",       /* 22 */
    "MaashPulu",        /* 23 */
    "Abgosht ",         /* 24 */
    "MosammaKadu",      /* 25 */
    "Mahey   ",         /* 26 */
    "KallePache"        /* 27 */
};

static uint32_t food_price_list[FD_MAX_FOOD]={
        0,    /*  "-",                None    */
     9500,    /* --- BreakFast                */
     9500,    /*  "Kare Asal",         01     */                   
     9500,    /*  "TokhmeMorgh",       02     */
     9500,    /*  "Adasi   ",          03     */
     9500,    /*  "Halva   ",          04     */
     9500,    /*  "Omlet   ",          05     */
     9500,    /*  "Kare Morabba",      06     */
     9500,    /*  "Sheer   ",          07     */
     9500,    /*  "KhameAsali",        08     */
     9500,    /*  "Panir   ",          09     */
    15400,    /*  --- Lunch & Dinner          */
    15400,    /*  "Kabaab  ",          10     */
    15400,    /*  "Morgh   ",          11     */
    15400,    /*  "Gheyme  ",          12     */
    15400,    /*  "Jooje   ",          13     */
    15400,    /*  "GhormeSabzi",       14     */
    15400,    /*  "AdasPolo",          15     */
    15400,    /*  "Meygoo  ",          16     */
    13500,    /*  "KuKuSibzaminy",     17     */
    13500,    /*  "LubiaPulu",         18     */
    13500,    /*  "Tone Mahey",        19     */
    13500,    /*  "KashkBademjan",     20     */
    13500,    /*  "Makaroni",          21     */
    13500,    /*  "ShevidPulu",        22     */
    13500,    /*  "MaashPulu",         23     */
    13500,    /*  "Abgosht ",          24     */
    13500,    /*  "MosammaKadu",       25     */
    13500,    /*  "Mahey   ",          26     */
    13500     /*  "KallePache"         27     */
};

static int food_week_num_list [] = {
    /* Saturday */
    1,2,   /* BreakFast */
    10,11, /* Lunch  */
    12,13, /* Dinner */

    /* Sunday */
    3,4,   /* BreakFast */
    14,15, /* Lunch  */
    16,17, /* Dinner */

    /* Monday */
    5,6,   /* BreakFast */
    18,19, /* Lunch  */
    20,21, /* Dinner */

    /* Tuesday */
    7,8,   /* BreakFast */
    22,23, /* Lunch  */
    24,25, /* Dinner */

    /* Tuesday */
    9,1,   /* BreakFast */
    26,27, /* Lunch  */
    10,11, /* Dinner */

    /* Wednesday */
    2,3,   /* BreakFast */
    12,13, /* Lunch  */
    14,15, /* Dinner */

    /* Thursday */
    4,5,   /* BreakFast */
    16,17, /* Lunch  */
    18,19, /* Dinner */

    /* Friday */
    6,7,   /* BreakFast */
    20,21, /* Lunch  */
    22,23  /* Dinner */
};

/* Get identifire of food */
int food_get_id (int day ,int meal ,int nfood){ 
    if (nfood >= FD_MAX_FOOD_PER_MEAL)
        return 0;
    return food_week_num_list[day*FD_MAX_FOOD_PER_DAY+meal*FD_MAX_FOOD_PER_MEAL+nfood];
}

char* food_get_name (int id){
    return food_name_list[id];
}

uint32_t food_get_price (int id){
    return food_price_list[id];
}

int food_get_max_day (){
    return FD_MAX_DAY;
}

int food_get_max_meal (){
    return FD_MAX_MEAL;
}

static char day_name [7][10]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};

char* food_get_day_name (int day){
    return day_name[day];
}