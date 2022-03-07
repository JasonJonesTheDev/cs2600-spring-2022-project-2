#include "header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include "car.c"
// #include "printCar.c"
// #include "meal.c"



float totalAllowableCalc(int, float, float, float, float);
void printTimes(int, int);

static int totalMeal_cost;

/***************  struct ***************/
struct meal_cost
{
    float total_mealCost;
    float extra_mealCost;
    float allowable_mealCost;
};

int main()
{
    /* Variables */
    float totalExpense = 0;
    float totalAlowableExpense=0;
    float outOfPocket=0;
    float unUsedFunds=0;

    int numOfDays=0;
    int departureTime=0;
    int arrivalTime=0;
    float gasCost=0;
    float airfair=0;
    float carRental=0;
    float milesReimbers=0;
    float parkingFees=0;
    float taxiFees=0;
    float registrationFees=0;
    float hotelExpense=0;

    printf("\t Welcome to \"TERC\"\n");
    printf("Travel Expense Reimbursement Calculator\n");
    printf("---------------------------------------\n");
    printf("\n");

    numOfDays = number_of_days();
    departureTime = get_departure_time();
    arrivalTime = get_arrival_time();
    //---------------------------------------------------------------------

    // The amount of each meal eaten and total meal cost after compensation.
    // use pointer to modify the data of allowable cost, and passed it in function call_by_main()
    float *totalAllowableCost;

    float totalMealsCost = call_by_main(numOfDays, departureTime, arrivalTime, totalAllowableCost);

    printf("\n----------------\nTotal cost of the entire trip is $%.2f\n", totalMealsCost);
    printf("Total allowable cost of entire trip is $%.2f\n", (totalAllowableCost));

    // get the data content valid of pointer totalAllowableCost
    // create another pointer hi and assigned it to the address of pointer totalAllowableCost
    float *hi = &(totalAllowableCost);

    // finally dispaly the data content ...... that was modified in functions in panda.c
    printf("Total allowable cost of entire trip is $%.2f\n", hi);

    //------------------------------------------------------------------------
    // Call whatever function is required for meals.
    airfair = airfare();
    hotelExpense = hotelFees(numOfDays);
    carRental = carRentalFees();
    taxiFees = calculateTaxiFees(numOfDays);

    if (carRental == 0)
    {
        gasCost = mileFees();
    }

    parkingFees = calculateParkingFees(numOfDays);
    registrationFees = conferenceFees();

    totalExpense += (airfair + hotelExpense + carRental + taxiFees + parkingFees + registrationFees); // add meal cost total
    totalAlowableExpense = totalAllowableCalc(numOfDays, airfair, carRental, gasCost, registrationFees);

    printf("\n");
    printf("---------------Overview----------------\n");
    printTimes(arrivalTime, departureTime);
    printf("Airfare: $%.2f\n", airfair);
    printf("Hotel Cost: $%.2f\n", hotelExpense);
    printf("Total Meal Cost: \n");
    printf("Car Rental Fees: $%.2f\n", carRental);
    printf("Gas Reimbursement: $%.2f\n", gasCost);
    printf("Taxi Fees: $%.2f\n", taxiFees);
    printf("Parking Fees: $%.2f\n", parkingFees);
    printf("Registration Fees: $%.2f\n", registrationFees);
    printf("\n");
    printf("----------------Totals-----------------\n");
    printf("Total Allowable Expense: $%.2f\n", totalAlowableExpense);
    printf("Total Expenses: $%.2f\n", totalExpense);

    if (totalExpense > totalAlowableExpense)
    { // checking if total expense is greater than allowable

        outOfPocket = amountExcess(totalAlowableExpense, totalExpense); // get difference
    }
    else if (totalExpense < totalAlowableExpense)
    { // checking if total expense is less than allowable

        unUsedFunds = amountSaved(totalAlowableExpense, totalExpense); // get difference
    }
    else
    {
        unUsedFunds = amountSaved(totalAlowableExpense, totalExpense);
    }

    char x[10];
    printf("\n");
    printf("Enter anything to close ");
    scanf("%s", &x);
    return 0;
}

/* Calculates Total Allowable Based On Values Given*/
float totalAllowableCalc(int days, float airfare, float carRentalFees, float milesExpense, float registrationFees)
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

    return totalAllowable;
}

void printTimes(int arrival, int departure)
{
    if (departure > 12)
    {
        printf("Departure Time: %d:00 pm\n", (departure - 12));
    }
    else
    {
        printf("Departure Time: %d:00 am\n", departure);
    }

    if (arrival > 12)
    {
        printf("Arrival Time: %d:00 pm\n", (arrival - 12));
    }
    else
    {
        printf("Arrival Time: %d:00 am\n", arrival);
    }
}