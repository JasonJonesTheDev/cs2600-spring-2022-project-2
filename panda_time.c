/**
 * panda_time.c
 *
 */
/***************  header file ***************/
#include <stdio.h>

#define numDays number_of_days ()


/***************  prototype ***************/
int number_of_days ();
int get_arrival_time ();
int get_departure_time();


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

        else {
            printf("You spent total %d days on the trip.\n", num_days);
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
    } else if (input > 24) {
        printf("Time can not exceed 24:00.\n");
        goto GET_TIME;
    } else {
        printf("You enter: %d\n", input);
    }

    return input;
}


int get_departure_time() {
    printf("--- Departure Time ---\n");
    return get_time();
}


int get_arrival_time () {
    printf("--- Arrival Time ---\n");
    return get_time();
}



