/**
 * meal.c
 *
 * get user input for each meal,
 *
 * calculate total and allowable cost
 *
 * announce total allowable cost for the entire trip to make their employees cry
 *
 */
/***************  header file ***************/
#include <stdio.h>



/***************  struct ***************/
struct Meal {
   float breakfast;
   float lunch;
   float dinner;
   float daily_totalCost;
} ;



/***************  prototype ***************/
float call_by_main(const int number_of_days, int departure_time, int arrival_time);
float getCost(const int number_of_days, struct Meal *meal_cost);

float firstDay_mealRule (struct Meal *meal_cost, int departure_time);
float lastDay_mealRule (struct Meal *meal_cost, int arrival_time, int number_days);

float otherDay_mealRule(struct Meal *meal_cost, int number_days);




/***************  functions ***************/
/**
 * ask for input,
 * do not accept negative number for meal cost
 * return the allowable total cost back to main
 */
float call_by_main(const int number_of_days, int departure_time, int arrival_time)
{
    printf("\nCost of Each Meals: \n");
//    printf("number of days = %d, departure time = %d, arrival time = %d\n",
//           number_of_days, departure_time, arrival_time);

    // create an array of struct Meal to store 3 meals for each day
    struct Meal meal_cost[number_of_days];

    for (int i = 0; i < number_of_days; ++i) {
        meal_cost[i].breakfast = 0.0;
        meal_cost[i].lunch = 0.0;
        meal_cost[i].dinner = 0.0;
        meal_cost[i].daily_totalCost = 0.0;
    }


    // ask user input for each meal cost, stored them into the array of struct Meal

    float total_cost = getCost(number_of_days, meal_cost);

    // count allowable cost for meals
    float total_allowable = 0.0;

    total_allowable += firstDay_mealRule(meal_cost, departure_time);

    total_allowable += lastDay_mealRule(meal_cost, arrival_time, number_of_days);

    total_allowable += otherDay_mealRule(meal_cost, number_of_days);

    printf("\n----------------\nTotal allowable cost for meal is $%.2f\n", total_allowable);

    return total_allowable;
}


// return total cost for the entire trip
float getCost(const int number_of_days, struct Meal *meal_cost) {

    float total = 0.0;

    for (int counter = 0; counter < number_of_days ; ++counter) {

        while(1) {

            // reset to 0.0 for each iteration (count daily cost)

            float breakfast = 0, lunch = 0, dinner = 0;

            printf("----- DAY %d -----\n", (counter+1));

            printf("Please enter the cost of breakfast, lunch and dinner (use spaces to separate):\n");

            scanf("%f %f %f", (&breakfast), (&lunch), (&dinner));

            if (breakfast < 0 || lunch < 0 || dinner < 0) {
                printf("Negative amount of cost is not acceptable.\n");
                continue; // return to beginning of while loop
            }

            else {

                meal_cost[counter].breakfast = breakfast;
                meal_cost[counter].lunch = lunch;
                meal_cost[counter].dinner = dinner;
                meal_cost[counter].daily_totalCost = (breakfast + lunch + dinner);

                total += meal_cost[counter].daily_totalCost;

                printf("Today's total cost = $%.2f\n", meal_cost[counter].daily_totalCost);

                break; // break out while loop, go to next iteration in for loop
            }
        }  // end of while

    } // end of for loop

    return total;

}


//  breakfast is allowed as an expense if the time of departure is before 7 a.m.
// Lunch is allowed if the time of departure is before 12 pm noon.
// Dinner is allowed on the first day if the time of departure is before 6 p.m.
float firstDay_mealRule (struct Meal *meal_cost, int departure_time)
{
    float total_allow = 0.0;

    if (departure_time < 7) {
        (total_allow) = meal_cost[0].daily_totalCost;
    } else if (departure_time < 12) {
        (total_allow) = (meal_cost[0].breakfast + meal_cost[0].lunch);
    } else if (departure_time < 18) {
        (total_allow) = meal_cost[0].dinner;
    } else {
        (total_allow) = 0.0;
    }

   // printf("Testing: first day total allowable cost is $%.2f\n", (total_allow));
    return total_allow;
}



//    On the last day of the trip, breakfast is allowed if the time of arrival is after 8 a.m.
//    Lunch is allowed if the time of arrival is after 1 p.m.
//     Dinner is allowed on the last day if the time of arrival is after 7 p.m.
float lastDay_mealRule (struct Meal *meal_cost, int arrival_time, int number_days) {

    float total_allow = 0.0;

    // no meal allowed if before 8
    if (arrival_time < 8) {
       total_allow = 0.0;
    }

        // 8 am to 1 pm, only breakfast is allowed
    else if (arrival_time < 13) {
        (total_allow) = meal_cost[number_days].breakfast;
    }

        // 1pm - 7 pm, breakfast and lunch are allowed
    else if (arrival_time < 19) {
        (total_allow) = (meal_cost[number_days].breakfast + meal_cost[number_days].lunch);
    }

        // after 7 pm (19), all allowed so nobody's starving eventually...
    else {
        total_allow = (meal_cost[number_days].breakfast +
                        meal_cost[number_days].lunch + meal_cost[number_days].lunch);
    }

//     printf("\nTesting - last day total allowable cost is: $%.2f\n", total_allow);

    return total_allow;
}


/*
 * the company allows up to $9 for breakfast,
 * $12 for lunch,
 * and $16 for dinner.
 * Anything more than this must be paid by the employee.
 */
float otherDay_mealRule(struct Meal *meal_cost, int number_days) {

    float allow = 0.0;

    for (int i = 1; i < number_days - 1; ++i) {

       if ( (meal_cost[i].breakfast < 9) || (meal_cost[i].breakfast == 9) ) {
           allow += (meal_cost[i].breakfast);
       }
        if (  (meal_cost[i].lunch < 12) || (meal_cost[i].lunch == 12) ) {
            allow += (meal_cost[i].lunch);
        }

        if (  (meal_cost[i].dinner < 16) || (meal_cost[i].dinner == 16) ) {
            allow += (meal_cost[i].dinner);
        }

    }

    return allow;
}


