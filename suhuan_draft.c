#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int number_of_days ();
int get_hour();
char get_ampm ();
struct departure_arrival get_time(struct departure_arrival *time);

void daily_mealCost (float *breakfast, float *lunch, float *dinner,float *allow, float *extra, int i);

void lastDay_mealRule(const struct departure_arrival *arrival, float breakfast, float lunch, float dinner, float *allow, float *extra);
void firstDay_mealRule(const struct departure_arrival *departure, float breakfast, float lunch, float dinner, float *allow, float *extra);


struct departure_arrival {
   int hour;
   char* ampm;
};

struct meal_cost {
   float allowable_mealCost;
   float extra_mealCost;
};


//
//int main() {
//    
//    foo();
//    return 0;
//}



//int departure;
//int arrival;


void foo()
{

    int numDays = number_of_days ();

    printf("\n----- The time of departure on the first day of the trip -----\n");
    struct departure_arrival departure;
    departure = get_time(&departure);
    printf("You departure time is: %d %s\n", departure.hour, departure.ampm);


    float breakfast1 = 0.0;
    float lunch1 = 0.0;
    float dinner1 = 0.0;
    float allow1 = 0.0;
    float extra1 = 0.0;
    daily_mealCost(&breakfast1, &lunch1, &dinner1, &allow1, &extra1, 1);

    struct meal_cost first_day;
    firstDay_mealRule(&departure, breakfast1, lunch1, dinner1, &allow1, &extra1);
    printf("First day total meal cost: %f, allow meal cost: %f\n", (allow1+extra1), allow1);

    printf("---------------------------------------------------------\n\n");



    printf("\n----- The time of arrival on the last day of the trip -----\n");
    struct departure_arrival arrival;
    arrival = get_time(&arrival);
    printf("You arrival time is: %d %s\n", arrival.hour, arrival.ampm);

    float breakfast0 = 0.0;
    float lunch0 = 0.0;
    float dinner0 = 0.0;
    float allow0 = 0.0;
    float extra0 = 0.0;

    daily_mealCost(&breakfast0, &lunch0, &dinner0, &allow0, &extra0, numDays);

    struct meal_cost last_day;
    lastDay_mealRule(&arrival, breakfast0, lunch0, dinner0, &allow0, &extra0);
    printf("Last day total meal cost: %f, allow meal cost: %f\n", (allow0+extra0), allow0);

    printf("---------------------------------------------------------\n\n");


}



void daily_meal_cost(float allow, float extra, struct meal_cost *day, int i)
{
    (*day).allowable_mealCost = allow;
    (*day).extra_mealCost = extra;

    printf("Allowable meal cost: $%f, extra meal expenses: $%f\n",
           (*day).allowable_mealCost, (*day).extra_mealCost);

    float totalMealsCost = (*day).allowable_mealCost + (*day).extra_mealCost;
    printf("Total meal cost: $%f\n", totalMealsCost);
}

//  breakfast is allowed as an expense if the time of departure is before 7 a.m.
// Lunch is allowed if the time of departure is before 12 pm noon.
// Dinner is allowed on the first day if the time of departure is before 6 p.m.
void firstDay_mealRule(const struct departure_arrival *departure, float breakfast, float lunch, float dinner, float *allow, float *extra)
{
    if (strcmp((*departure).ampm, "am") == 0) {

        // depart 0 am - 6 am: all allowed
        if ((*departure).hour < 7) {
            (*allow) += breakfast;
            (*allow) += lunch;
            (*allow) += dinner;
        }

        // 7 am - 11 am, lunch and dinner allowed
        else if ((*departure).hour < 12) {
            (*allow) += lunch;
            (*allow) += dinner;
        }

        // depart @12 am (midnight)
        else {
            (*extra) += breakfast;
            (*extra) += lunch;
            (*extra) += dinner;
        }
    }

    else if ( (strcmp((*departure).ampm, "pm") == 0) ) {

        // depart @ 12pm - 6 pm
        if ( ((*departure).hour < 6) || ((*departure).hour == 12) ) {
            (*allow) += dinner;
            (*extra) += lunch;
            (*extra) += breakfast;
        }

        // depart @ 6 pm - 11 pm
        else if ( ((*departure).hour > 6) && ((*departure).hour < 12) ) {
            (*extra) += breakfast;
            (*extra) += lunch;
            (*extra) += dinner;
        }

        else {
            printf("something wrong...\n");
            EXIT_FAILURE;
        }
    }

    else {
        printf("something wrong...\n");
        EXIT_FAILURE;
    }
}




//    On the last day of the trip, breakfast is allowed if the time of arrival is after 8 a.m.
//    Lunch is allowed if the time of arrival is after 1 p.m.
//     Dinner is allowed on the last day if the time of arrival is after 7 p.m.
void lastDay_mealRule(const struct departure_arrival *arrival, float breakfast,
                      float lunch, float dinner, float *allow, float *extra)
{
    if (strcmp((*arrival).ampm, "am") == 0) {

        // depart 0 am - 8 am: all count for extra
        if ((*arrival).hour < 8) {
            (*extra) += breakfast;
            (*extra) += lunch;
            (*extra) += dinner;
        }

        // 8 am - 12 pm, only breakfast is allowed
        else if ((*arrival).hour < 12) {
            (*allow) += breakfast;
            (*extra) += dinner;
            (*extra) += lunch;
        }

        // depart @12 am (midnight)
        else {
            (*extra) += breakfast;
            (*extra) += lunch;
            (*extra) += dinner;
        }
    }

    else if ( (strcmp((*arrival).ampm, "pm") == 0) ) {

        // @ 12 pm, only breakfast is allowed
        if ( (*arrival).hour == 12 )  {
            (*extra) += dinner;
            (*extra) += lunch;
            (*allow) += breakfast;
        }

            // depart @ 1 pm - 7 pm, lunch breakfast are allowed
        else if (((*arrival).hour < 7) ) {
            (*allow) += breakfast;
            (*allow) += lunch;
            (*extra) += dinner;
        }

        // depart @ 8 pm - 11 pm, all allow
        else {
            (*allow) += breakfast;
            (*allow) += lunch;
            (*allow) += dinner;
        }
    }

    else {
        printf("something wrong...\n");
        EXIT_FAILURE;
    }
}


void daily_mealCost (float *breakfast, float *lunch, float *dinner,float *allow, float *extra, int i)
{
    printf("\n----- The amount of each meal eaten -----\n");
    printf("DAY %d:\n", i);

    printf("Please enter the cost of breakfast, lunch and dinner (use space to separate):\n");
    scanf("%f %f %f", breakfast, lunch, dinner);

    printf("breakfast: $%f; lunch: $%f; dinner: $%f\n", (*breakfast), (*lunch), (*dinner));


    // The company allows up to $9 for breakfast, $12 for lunch, and $16 for dinner.
    // Anything more than this must be paid by the employee.)
    float a = 0, e = 0;

    if ( (*breakfast) < 9 ) {
        a += (*breakfast);
    } else {
        e += (*breakfast);
    }

    if ( (*lunch) < 12 ) {
        a += (*breakfast);
    } else {
        e += (*lunch);
    }

    if ( (*dinner) < 16 ) {
        a += (*dinner);
    } else {
        e += (*dinner);
    }


}

struct departure_arrival get_time(struct departure_arrival *time)
{
    (*time).hour = get_hour();
    char c = get_ampm();

    if (c == 'a') {
        (*time).ampm = "am";

    }
    else if (c == 'p') {
        (*time).ampm = "pm";
    }
    else {
        printf("Something wrong...\n");
        EXIT_FAILURE;
    }
    return (*time);
}

/* The total number of days spent on the trip
   const int numDay;
   Do not accept numbers less than 1 for the number of days.
 */
int number_of_days () {

    int num_days = 0;

    do {
        printf("Please enter the total number of days spent on the trip: ");

        scanf("%d", &num_days);

        if (num_days < 1) {
            printf("Invalid input: the number of days cannot be less than 1.\n");
            continue;
        }

        else {
            printf("You spent total %d days on the trip.\n", num_days);
        }

    } while (num_days < 1);

    return num_days;


}


int get_hour() {

    int hour;

    POSITIVE: printf("Please enter the time: ");

        scanf("%d", &hour);

        if ((hour > 12) || (hour < 0))  {
            printf("Invalid input: number 0 to 12 only.\n");
            goto POSITIVE;
        }

        else {
           return hour;
        }

}




char get_ampm () {

    char input;

    AM_PM: printf("enter 'a' for am, 'p' for pm: ");
    scanf(" %c", &input);

        switch (input) {
            case 'a':
            case 'A':
                return 'a';

            case 'p':
            case 'P':
                return 'p';

            default:
                printf("Invalid input.\n");
                goto AM_PM;
        } // end of switch
}




