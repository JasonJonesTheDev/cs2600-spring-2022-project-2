#include "header.h"

float mealLogic(numOfDays, departureTime, arrivalTime)
{
    int mealIndex = 0;
    float total = 0;
    int lastDay = numOfDays;
    float breakfast = 0;
    float lunch = 0;
    float dinner = 0;

    if (departureTime < 7 && arrivalTime > 17)
    {
        total = dailyMealsAdder(numOfDays, mealIndex);
        return total;
    }
    else if (departureTime >= 12)
    {
        numOfDays--;
        mealIndex++;
        total = dailyMealsAdder(numOfDays, mealIndex);
    }
    else if (departureTime >= 18)
    {
        numOfDays--;
        mealIndex = 1;
        total = dailyMealsAdder(numOfDays, mealIndex);
    }

    printf("-- Day %d --", &lastDay);

    if (arrivalTime >= 8)
    {
        int cont = 1;
        while (cont == 1)
        {
            printf("Enter Lunch Cost: $");
            scanf("%f", &lunch);
            printf("Enter Dinner Cost: $");
            scanf("%f", &dinner);
            if (breakfast < 0 || lunch < 0 || dinner < 0)
            {
                printf("Please Enter Values Of At Least 0\n");
            }
            else
            {
                total += (breakfast + lunch + dinner);
                cont = 0;
            }
        }
    }
    else if (arrivalTime >= 13)
    {
        int cont = 1;
        while (cont == 1)
        {
            printf("Enter Dinner Cost: $");
            scanf("%f", &dinner);
            if (breakfast < 0 || lunch < 0 || dinner < 0)
            {
                printf("Please Enter Values Of At Least 0\n");
            }
            else
            {
                total += (breakfast + lunch + dinner);
                cont = 0;
            }
        }
    }
    else
        return total;
}
float dailyMealsAdder(numOfDays, mealIndex)
{
    float breakfast = 0;
    float lunch = 0;
    float dinner = 0;
    float total = 0;

    for (int i = 0; i < numOfDays; i++)
    {
        for (mealIndex; mealIndex < 2; mealIndex++)
        {
            int cont = 1;
            while (cont == 1)
            {
                if (mealIndex = 0)
                {
                    printf("-- Day %d --\n", (i + 1));
                    printf("Enter Breakfast cost: $");
                    scanf("%f", &breakfast);
                }
                else if (mealIndex = 1)
                {
                    printf("Enter Lunch Cost: $");
                    scanf("%f", &lunch);
                }
                else if (mealIndex = 2)
                {
                    printf("Enter Dinner Cost: $");
                    scanf("%f", &dinner);
                }
                if (breakfast < 0 || lunch < 0 || dinner < 0)
                {
                    printf("Please Enter Values Of At Least 0\n");
                }
                else
                {
                    total += (breakfast + lunch + dinner);
                    cont = 0;
                }
            }
        }
    }
    return total;
}

/* Calculates Total Allowable Based On Values Given*/
float totalAllowableCalc(int days, float airfare, float carRentalFees, float milesExpense, float registrationFees, int departure, int arrival)
{
    float totalAllowable = 0;

    totalAllowable += airfare;
    totalAllowable += carRentalFees;
    totalAllowable += milesExpense;
    totalAllowable += (days * 6);  // parking fees
    totalAllowable += (days * 10); // taxi fees
    totalAllowable += registrationFees;
    totalAllowable += (days * 90);                              // hotel fees
    totalAllowable += ((days * 9) + (days * 12) + (days * 16)); // meal cost max

    if (departure < 7)
    {
        // lunch breakfast and dinner
    }
    else if (departure >= 7 && departure < 12)
    {
        // lunch and dinner
        totalAllowable -= (9);
    }
    else if (departure >= 12 && departure < 18)
    {
        // dinner only
        totalAllowable -= (9 + 12);
    }
    else
    {
        // none
        totalAllowable -= (9 + 12 + 16);
    }

    if (arrival >= 8 && arrival < 13)
    {
        // only breakfast
        totalAllowable -= (12 + 16);
    }
    else if (arrival >= 13 && arrival < 19)
    {
        // lunch and breakfast
        totalAllowable -= (16);
    }
    else if (arrival >= 19)
    {
        // lunch breakfast and dinner
    }
    else
    {
        // none
        totalAllowable -= (9 + 12 + 16);
    }
    return totalAllowable;
}

// /**
//  * meal.c
//  *
//  * get user input for each meal,
//  *
//  * calculate total and allowable cost
//  *
//  * announce total allowable cost for the entire trip to make their employees cry
//  *
//  */
// /***************  header file ***************/
// #include <stdio.h>

// /***************  struct ***************/
// struct Meal {
//    float breakfast;
//    float lunch;
//    float dinner;
//    float daily_totalCost;
// } ;

// /***************  prototype ***************/

// float call_by_main(const int number_of_days, int departure_time, int arrival_time, float *total_allowable);

// float user_input_mealCost(const int number_of_days, struct Meal *meal_cost);

// void firstDay_mealRule (struct Meal *meal_cost, int departure_time, float *ptr_allow);

// void lastDay_mealRule (struct Meal *meal_cost, int arrival_time, int number_days, float *ptr_allow);

// float commonRule(const int number_of_days, struct Meal *meal_cost);

// /***************  functions ***************/

// /**
//  * return the modified data content of pointer by passing parameter arg[3]
//  * return total cost back to main
//  */
// float call_by_main(const int number_of_days, int departure_time, int arrival_time, float *total_allowable)
// {
// //    printf("number of days = %d, departure time = %d, arrival time = %d\n",
// //           number_of_days, departure_time, arrival_time);

//     // create an array of struct Meal to store 3 meals for each day
//     struct Meal meal_cost[number_of_days];

//     // get the value of total cost
//     float total_cost = user_input_mealCost(number_of_days, meal_cost);

//     float allow = commonRule(number_of_days, meal_cost);

//     total_allowable = &allow;

// //    printf("=== After asked user input, the data value of pointer is: %.2f ===\n",
// //          *total_allowable);

//     // the data content of pointer total_allowable haven't counted the weird rule of first/last day
//     // subtract corresponding meal cost according to its corresponding time limit on that time
//     firstDay_mealRule(meal_cost, departure_time, total_allowable);
// //    printf("\n\n=== After applying first day rule, the data value of pointer is: %.2f ===\n\n",
// //           *total_allowable);

//     lastDay_mealRule(meal_cost, arrival_time, number_of_days, total_allowable);
// //    printf("\n\n=== After applying last day rule, the data value of pointer is: %.2f ===\n\n",
// //           *total_allowable);

// //    printf("\n----------------\nTotal cost of the entire trip is $%.2f\n", total_cost);
// //
// //    printf("Total allowable cost for meal is $%.2f\n", *total_allowable);

//     return total_cost;
// }

// // return total cost for the entire trip
// // ask for input,
// // do not accept negative number for meal cost
// float user_input_mealCost(const int number_of_days, struct Meal *meal_cost) {

//     float total = 0.0F, allow = 0.0F;

//     for (int counter = 0; counter < number_of_days ; ++counter) {

//         while(1) {

//             // reset to 0.0 for each iteration (count daily cost)
//             float breakfast = 0, lunch = 0, dinner = 0;

//             printf("----- DAY %d -----\n", (counter+1));

//             printf("Please enter the cost of breakfast, lunch and dinner (use spaces to separate):\n");

//             scanf("%f %f %f", (&breakfast), (&lunch), (&dinner));

//             if (breakfast < 0 || lunch < 0 || dinner < 0) {
//                 printf("Negative amount of cost is not acceptable.\n");
//                 continue; // return to beginning of while loop
//             }

//             else {

//                 meal_cost[counter].breakfast = breakfast;
//                 meal_cost[counter].lunch = lunch;
//                 meal_cost[counter].dinner = dinner;
//                 meal_cost[counter].daily_totalCost = (breakfast + lunch + dinner);

//                 total += meal_cost[counter].daily_totalCost;
//                 printf("Today's total cost = $%.2f\n", meal_cost[counter].daily_totalCost);

//                 break; // break out while loop, go to next iteration in for loop
//             }
//         }  // end of while

//     } // end of for loop

//     return total;
// }

// /*
//  * common meal rule:
//  * the company allows up to $9 for breakfast,
//  * $12 for lunch,
//  * and $16 for dinner.
//  * Anything more than this must be paid by the employee.
//  * <=> anything less than that, add up the value to the content of pointer ptr_allow
//  */
// float commonRule(const int number_of_days, struct Meal *meal_cost)
// {
//     float  allow = 0.0F;

//     for (int i = 0; i < number_of_days; ++i) {

//         if (meal_cost[i].breakfast > 9) {
//             allow += 9;
//         } else {
//             allow += (meal_cost[i].breakfast);
//         }

//         if (meal_cost[i].lunch > 12) {
//             allow += 12;
//         } else {
//             allow += meal_cost[i].lunch;
//         }

//         if (meal_cost[i].dinner > 16) {
//             allow += 16;
//         } else {
//             allow += meal_cost[i].dinner ;
//         }

//     }

//  //   printf("\n\n=== After applying common rules, allowable meal cost is $%.2f ===\n\n", allow);

//     return allow;
// }

// //  breakfast is allowed as an expense if the time of departure is before 7 a.m.
// // Lunch is allowed if the time of departure is before 12 pm noon.
// // Dinner is allowed on the first day if the time of departure is before 6 p.m.
// // --> subtract meal cost if the departure time was too late / arrival time was too early
// void firstDay_mealRule (struct Meal *meal_cost, int departure_time, float *ptr_allow)
// {
//      // float allow = 0.0F;

//     // before 7, all meals are allowed ==> no subtraction at all
//     // 7-24, no breakfast
//     if (departure_time > 7) {
//         (*ptr_allow) = (meal_cost[0].breakfast);
//     }

//     // 12 - 24, no lunch as well
//     if (departure_time > 12) {
//         (*ptr_allow) -= (meal_cost[0].lunch);
//     }

//     // 18 - 24, dinner is not allowed
//     if (departure_time > 18) {
//         (*ptr_allow) -= (meal_cost[0].dinner);
//     }
// //
// //    printf("I am a ghost, I just silently took out money from late people on the first day.\n");
// //    printf("Total allowable cost: $%.2f\n", (*ptr_allow));
// }

// //    On the last day of the trip, breakfast is allowed if the time of arrival is after 8 a.m.
// //    Lunch is allowed if the time of arrival is after 1 p.m.
// //     Dinner is allowed on the last day if the time of arrival is after 7 p.m.
// void lastDay_mealRule (struct Meal *meal_cost, int arrival_time, int number_days, float *ptr_allow) {

//     int lastDay = number_days - 1;

//     // no meal allowed if before 8, so early bird will be starving @ 0 - 8
//     if (arrival_time < 8) {
//         (*ptr_allow) -= (meal_cost[lastDay].daily_totalCost);
//     }

//     // @8 - 12, breakfast allowed, subtract lunch and dinner
//     else if (arrival_time < 13) {
//         (*ptr_allow) -= (meal_cost[lastDay].lunch);
//         (*ptr_allow) -= (meal_cost[lastDay].dinner);
//     }

//     // 13 - 19, breakfast and lunch are allowed, subtract dinner only
//     else if (arrival_time < 19) {
//         (*ptr_allow) -= (meal_cost[lastDay].dinner);
//     }

//     else {
//         // after 19, all allowed --> no subtraction @ 19 - 24
//     }

// //    printf("I am a ghost, I just silently took out money from early birds on the last day.\n");
// //    printf("Total allowable cost: $%.2f\n", *(ptr_allow));
// }
