#ifndef _FOOD_H
#define _FOOD_H
#include <stdint.h>

#define FD_MAX_FOOD_PER_MEAL 2   /* Maximum of food per meal in list */
#define FD_MAX_MEAL 3     /* Max meal */
#define FD_MAX_DAY 7      /* 7 day in week */

#define FD_MAX_FOOD_PER_DAY FD_MAX_MEAL*FD_MAX_FOOD_PER_MEAL

#define FD_MAX_FOOD FD_MAX_FOOD_PER_MEAL*FD_MAX_MEAL*FD_MAX_DAY /* Maximun Number of Foods */
#define FD_MAX_NAME 20    /* Maximum char of food name */

int food_get_id (int day ,int meal ,int nfood);
char* food_get_name (int id);
uint32_t food_get_price (int id);
int food_get_max_day ();
int food_get_max_meal ();
char* food_get_day_name (int day);

#endif