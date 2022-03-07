/**
 * panda.c
 *
 * lvalue is the local variable from main() in main.c
 *
 * - ask and display the total number of days spent on the trip
 * const int numOfDays = numDays;
 *
 * - the departure / arrival time
 *  double departureTime = departure_time;
 *  double arrivalTime = ARRIVAL_TIME;
 *
 *
 *
 */
/***************  header file ***************/
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
#include "header.h"

//#define numDays number_of_days ()


/***************  prototype ***************/
// int number_of_days ();
// int get_time();
// void get_mealCost (float *breakfast, float *lunch, float *dinner);
// struct meal_cost * firstDay();
// void firstDay_mealRule(float breakfast, float lunch, float dinner, float *allow, float *extra);

// int get_departure_time ();
// float total_mealCost(float breakfast_cost, float lunch_cost, float dinner_cost);
// int get_arrival_time ();
// void lastDay_mealRule(float breakfast, float lunch, float dinner, float *allow, float *extra);
// void otherDay_mealRule(float breakfast, float lunch, float dinner, float *allow, float *extra);

// void otherDay_mealRule(float breakfast, float lunch, float dinner, float *allow, float *extra);
// float get_totalMeal_cost(int number_of_days);

// void FirstDay (int *ptr_const);
// void LastDay (struct meal_cost *lastDay);
// void commonDay (struct meal_cost *commonDay);



/***************  global variables ***************/
int departure_time;
int arrival_time;

static int totalMeal_cost;


/***************  struct ***************/
struct meal_cost {

   float total_mealCost;
   float extra_mealCost;
   float allowable_mealCost;

} ;


/***************  functions ***************/
/*
 * int number_of_days()
 * function ask and display the total number of days spent on the trip
 * return an integer of The total number of days spent on the trip
 *  Do not accept numbers less than 1 for the number of days.
 */
int number_of_days () {

    int num_days;

    do {
        printf("Please enter the total number of days spent on the trip: ");

        scanf("%d", &num_days);

        if (num_days < 1) {
            printf("Invalid input: the number of days cannot be less than 1.\n");
            continue;
        }

    } while (num_days < 1);

    printf("\n");

    return num_days;
}

/**
 * @brief function int get_time()
 * @return an integer value to represent time from user input
 * validate time range 0 to 24
 */
int get_time()
{
    int input;

    GET_TIME: // label
    printf("Please enter the time in 24 hour format: 0 or 24 as 0 am, 12 as 12:00 pm, 13 as 1 pm\n");
    scanf(" %d", &input);

    if (input < 0) {
        printf("Time can not be a negative number.\n");
        goto GET_TIME;
    }

    else if (input > 24) {
        printf("Time can not exceed 24:00.\n");
        goto GET_TIME;
    }
    else {
        //printf("You enter: %d\n", input);
    }

    return input;
}

int get_departure_time () {
    printf("--- Departure Time ---\n");
    departure_time = get_time();
    printf("\n");
    return departure_time;
}

int get_arrival_time () {
    printf("--- Arrival Time ---\n");
    arrival_time = get_time();
    printf("\n");
    return arrival_time;
}



/**
 * simply ask for input,
 * do not accept negative number for meal cost
 */
void get_mealCost (float *breakfast, float *lunch, float *dinner)
{
    MEAL_COST:
    printf("Please enter the cost of breakfast, lunch and dinner (use space to separate):\n");
    scanf("%f %f %f", breakfast, lunch, dinner);

    if (breakfast < 0 || lunch < 0 || dinner < 0) {
        printf("Negative amount of cost is not acceptable.\n");
        goto MEAL_COST;
    } else {
        printf("You enter:\nbreakfast: $%.2f; lunch: $%.2f; dinner: $%.2f\n", (*breakfast), (*lunch), (*dinner));
    }
}



float get_totalMeal_cost(int number_of_days) {

    printf("get total meal cost: ");

    struct meal_cost *day_last;

    FirstDay(&totalMeal_cost);
    LastDay(day_last);

    for (int (i) = 2; (i) < (number_of_days - 2); ++(i)) {
        commonDay(day_last);
    }

    printf("\n--------- Total meal cost = $%.2f ---------\n", totalMeal_cost);

    return totalMeal_cost;

}



void FirstDay (int *ptr_const)
{

    printf("\n----- The time of departure on the first day of the trip -----\n");
    departure_time = get_time();
    struct meal_cost firstDay;

    float breakfast1 = 0;
    float lunch1 = 0;
    float dinner1 = 0;
    float allow1 = 0;
    float extra1 = 0;

    // use pointer to store the total cost of first day
    get_mealCost(&breakfast1, &lunch1, &dinner1);
    firstDay.total_mealCost = total_mealCost(breakfast1, lunch1, dinner1);

    (*ptr_const) += firstDay.total_mealCost;

    firstDay_mealRule(breakfast1, lunch1, dinner1, &allow1, &extra1);
    (firstDay).allowable_mealCost = allow1;
    (firstDay).extra_mealCost = extra1;

    printf("Allow: $%.2f, Extra: $%.2f\n",  (firstDay).allowable_mealCost,  (firstDay).extra_mealCost);

}


 void LastDay (struct meal_cost * lastDay)
{

    printf("\n----- The time of departure on the last day of the trip -----\n");
    arrival_time = get_time();

    float breakfast1 = 0;
    float lunch1 = 0;
    float dinner1 = 0;
    float allow1 = 0;
    float extra1 = 0;

    // use pointer to store the total cost of first day
    get_mealCost(&breakfast1, &lunch1, &dinner1);

    (*lastDay).total_mealCost = total_mealCost(breakfast1, lunch1, dinner1);

    lastDay_mealRule(breakfast1, lunch1, dinner1, &allow1, &extra1);

    (*lastDay).allowable_mealCost = allow1;
    (*lastDay).extra_mealCost = extra1;

    printf("Allow: $%.2f, Extra: $%.2f\n", (*lastDay).allowable_mealCost, (*lastDay).extra_mealCost );

}


void commonDay (struct meal_cost * commonDay)
{

    printf("\n----- Common Day Meal Cost -----\n");

    float breakfast1 = 0;
    float lunch1 = 0;
    float dinner1 = 0;
    float allow1 = 0;
    float extra1 = 0;

    get_mealCost(&breakfast1, &lunch1, &dinner1);

    (*commonDay).total_mealCost = total_mealCost(breakfast1, lunch1, dinner1);

    otherDay_mealRule(breakfast1, lunch1, dinner1, &allow1, &extra1);

    (*commonDay).allowable_mealCost = allow1;
    (*commonDay).extra_mealCost = extra1;

    totalMeal_cost +=  (*commonDay).total_mealCost;

    printf("Allow: $%.2f, Extra: $%.2f\n", (*commonDay).allowable_mealCost, (*commonDay).extra_mealCost);

}



float total_mealCost(float breakfast_cost, float lunch_cost, float dinner_cost)
{
    float total = (breakfast_cost) + (lunch_cost) + (dinner_cost);
    printf("Total meal cost: %.2f\n", total);
    return total;
}

//  breakfast is allowed as an expense if the time of departure is before 7 a.m.
// Lunch is allowed if the time of departure is before 12 pm noon.
// Dinner is allowed on the first day if the time of departure is before 6 p.m.
void firstDay_mealRule(float breakfast, float lunch, float dinner, float *allow, float *extra) {

    float total_allow = 0.0;
    float  total_extra = 0.0;

    if (departure_time < 7) {
        total_allow += (breakfast + lunch + dinner);
    }
    else if (departure_time < 12) {
        total_allow += (breakfast + lunch);
        total_extra += dinner;
    }
    else if (departure_time < 18) {
        total_extra += (breakfast + lunch);
        total_allow += dinner;
    }
    else {
        total_extra += (breakfast + lunch + dinner);
    }
}


//    On the last day of the trip, breakfast is allowed if the time of arrival is after 8 a.m.
//    Lunch is allowed if the time of arrival is after 1 p.m.
//     Dinner is allowed on the last day if the time of arrival is after 7 p.m.
void lastDay_mealRule(float breakfast, float lunch, float dinner, float *allow, float *extra) {

    float total_allow = 0.0;
    float total_extra = 0.0;

    // no meal allowed if before 8
    if (arrival_time < 8) {
        total_extra += (breakfast + lunch + dinner);
    }

        // 8 am to 1 pm, only breakfast is allowed
    else if (departure_time < 13) {
        total_allow += breakfast;
        total_extra += (dinner + lunch);
    }

        // 1pm - 7 pm, breakfast and lunch are allowed
    else if (departure_time < 19) {
        total_allow += (breakfast + lunch);
        total_extra += dinner;
    }

        // after 7 pm (19), all allowed so nobody's starving eventually...
    else {
        total_allow += (breakfast + lunch + dinner);
    }
}

/*
 * the company allows up to $9 for breakfast,
 * $12 for lunch,
 * and $16 for dinner.
 * Anything more than this must be paid by the employee.
 */
void otherDay_mealRule(float breakfast, float lunch, float dinner, float *allow, float *extra) {

    float total_allow = 0.0;
    float total_extra = 0.0;


    if (breakfast > 8) {
        total_extra += breakfast;
    } else {
        total_allow += breakfast;
    }

    if (lunch > 12) {
        total_extra += lunch;
    } else {
        total_allow += lunch;
    }

    if (dinner > 16) {
        total_extra += dinner;
    } else {
        total_allow += dinner;
    }


}



//        float allow1 = 0.0;
//        float extra1 = 0.0;
//
//        get_mealCost(&breakfast1, &lunch1, &dinner1, &allow1, &extra1, 1);
//
//        struct meal_cost first_day;
//        firstDay_mealRule(&departure, breakfast1, lunch1, dinner1, &allow1, &extra1);
//        printf("First day total meal cost: %f, allow meal cost: %f\n", (allow1+extra1), allow1);





//
//    printf("---------------------------------------------------------\n\n");
//
//
//
//
//    float breakfast0 = 0.0;
//    float lunch0 = 0.0;
//    float dinner0 = 0.0;
//    float allow0 = 0.0;
//    float extra0 = 0.0;
//
//    get_mealCost(&breakfast0, &lunch0, &dinner0, &allow0, &extra0, numDays);
//
//    struct meal_cost last_day;
//    lastDay_mealRule(&arrival, breakfast0, lunch0, dinner0, &allow0, &extra0);
//    printf("Last day total meal cost: %f, allow meal cost: %f\n", (allow0+extra0), allow0);
//
//    printf("---------------------------------------------------------\n\n");
//
//
//}
//

//
//
//void daily_meal_cost(float allow, float extra, struct meal_cost *day, int i)
//{
//    (*day).allowable_mealCost = allow;
//    (*day).extra_mealCost = extra;
//
//    printf("Allowable meal cost: $%f, extra meal expenses: $%f\n",
//           (*day).allowable_mealCost, (*day).extra_mealCost);
//
//    float totalMealsCost = (*day).allowable_mealCost + (*day).extra_mealCost;
//    printf("Total meal cost: $%f\n", totalMealsCost);
//}




//    if (strcmp((*departure).am_pm, "am") == 0) {
//
//        // depart 0 am - 6 am: all allowed
//        if ((*departure).hour < 7) {
//            (*allow) += breakfast;
//            (*allow) += lunch;
//            (*allow) += dinner;
//        }
//
//        // 7 am - 11 am, lunch and dinner allowed
//        else if ((*departure).hour < 12) {
//            (*allow) += lunch;
//            (*allow) += dinner;
//        }
//
//        // depart @12 am (midnight)
//        else {
//            (*extra) += breakfast;
//            (*extra) += lunch;
//            (*extra) += dinner;
//        }
//    }
//
//    else if ( (strcmp((*departure).am_pm, "pm") == 0) ) {
//
//        // depart @ 12pm - 6 pm
//        if ( ((*departure).hour < 6) || ((*departure).hour == 12) ) {
//            (*allow) += dinner;
//            (*extra) += lunch;
//            (*extra) += breakfast;
//        }
//
//        // depart @ 6 pm - 11 pm
//        else if ( ((*departure).hour > 6) && ((*departure).hour < 12) ) {
//            (*extra) += breakfast;
//            (*extra) += lunch;
//            (*extra) += dinner;
//        }
//
//        else {
//            printf("something wrong...\n");
//            EXIT_FAILURE;
//        }
//    }
//
//    else {
//        printf("something wrong...\n");
//        EXIT_FAILURE;
//    }
//}





//void lastDay_mealRule(const struct departure_arrival_time *arrival, float breakfast,
//                      float lunch, float dinner, float *allow, float *extra)
//{
//    if (strcmp((*arrival).am_pm, "am") == 0) {
//
//        // depart 0 am - 8 am: all count for extra
//        if ((*arrival).hour < 8) {
//            (*extra) += breakfast;
//            (*extra) += lunch;
//            (*extra) += dinner;
//        }
//
//        // 8 am - 12 pm, only breakfast is allowed
//        else if ((*arrival).hour < 12) {
//            (*allow) += breakfast;
//            (*extra) += dinner;
//            (*extra) += lunch;
//        }
//
//        // depart @12 am (midnight)
//        else {
//            (*extra) += breakfast;
//            (*extra) += lunch;
//            (*extra) += dinner;
//        }
//    }
//
//    else if ( (strcmp((*arrival).am_pm, "pm") == 0) ) {
//
//        // @ 12 pm, only breakfast is allowed
//        if ( (*arrival).hour == 12 )  {
//            (*extra) += dinner;
//            (*extra) += lunch;
//            (*allow) += breakfast;
//        }
//
//            // depart @ 1 pm - 7 pm, lunch breakfast are allowed
//        else if (((*arrival).hour < 7) ) {
//            (*allow) += breakfast;
//            (*allow) += lunch;
//            (*extra) += dinner;
//        }
//
//        // depart @ 8 pm - 11 pm, all allow
//        else {
//            (*allow) += breakfast;
//            (*allow) += lunch;
//            (*allow) += dinner;
//        }
//    }
//
//    else {
//        printf("something wrong...\n");
//        EXIT_FAILURE;
//    }
//}
//
//


//    // The company allows up to $9 for breakfast, $12 for lunch, and $16 for dinner.
//    // Anything more than this must be paid by the employee.)
//    float a = 0, e = 0;
//
//    if ((*breakfast) < 9) {
//        a += (*breakfast);
//    } else {
//        e += (*breakfast);
//    }
//
//    if ((*lunch) < 12) {
//        a += (*breakfast);
//    } else {
//        e += (*lunch);
//    }
//
//    if ((*dinner) < 16) {
//        a += (*dinner);
//    } else {
//        e += (*dinner);
//    }
//}

//
//}
//
//struct departure_arrival_time get_time(struct departure_arrival_time *time)
//{
//    (*time).hour = get_hour();
//    char c = get_ampm();
//
//    if (c == 'a') {
//        (*time).am_pm = "am";
//    }
//    else if (c == 'p') {
//        (*time).am_pm = "pm";
//    }
//    else {
//        printf("Something wrong...\n");
//        EXIT_FAILURE;
//    }
//    return (*time);
//}
//
//
//int get_hour() {
//
//    int hour;
//
//    POSITIVE: printf("Please enter the time: ");
//
//        scanf("%d", &hour);
//
//        if ((hour > 12) || (hour < 0))  {
//            printf("Invalid input: number 0 to 12 only.\n");
//            goto POSITIVE;
//        }
//
//        else {
//           return hour;
//        }
//
//}
//
//
//
//
//char get_ampm () {
//
//    char input;
//
//    AM_PM: printf("enter 'a' for am, 'p' for pm: ");
//    scanf(" %c", &input);
//
//        switch (input) {
//            case 'a':
//            case 'A':
//                return 'a';
//
//            case 'p':
//            case 'P':
//                return 'p';
//
//            default:
//                printf("Invalid input.\n");
//                goto AM_PM;
//        } // end of switch
//}
//
//
//


