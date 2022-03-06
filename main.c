#include "header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include "printCar.c"
// #include "car.c"

/***************  global variables ***************/
// int departure_time;
// int arrival_time;

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

    // // Variables
    // // The running total allowable expenses for the trip
    // float totalExpense;
    // // The running total expenses incurred by the traveler,
    // float totalAlowableExpense;
    // // The excess that must be reimbursed by the traveler, if any.
    // float outOfPocket;
    // // The amount saved by the company/business person if the expenses
    // // were under the total allowed.
    // float unUsedFunds;
    // // Total possible amount traveler can receive
    // float maximumFunds;
    // // Total days traveled
    // // int numOfDays;
    // // The time of departure on the first day of the trip,
    // // and the time of arrival back home on the last day of the trip.
    // int departureTime;
    // int arrivalTime;
    // // The amount of any round-trip airfare
    // float airfair;
    // // The amount of any car rentals
    // float carRental;
    // // Miles driven, if a private vehicle was used.
    // // Calculate the vehicle expense as $0.27 per mile driven
    // int milesDriven;
    // float milesReimbers;
    // // Parking fees (The company allows up to $6 per day.
    // // Anything more than this must be paid by the employee.)
    // float parkingFees;
    // // Taxi fees, if a taxi was used anytime during the trip
    // // (The company allows up to $10 per day, for each day a taxi was used.
    // // Anything more than this must be paid by the employee.)
    // float taxiFees;
    // // Conference or seminar registration fees
    // float registrationFees;
    // // Hotel expenses (The company allows up to $90 per night for lodging.
    // // Anything more than this must be paid by the employee.)
    // float hotelExpense;
    // // The amount of each meal eaten and total meal cost after compensation.
    // float breakfast;
    // float lunch;
    // float dinner;
    // float totalMealsCost;

    //  maximumFunds = (airFair + carRental + totalMealsCost + )
    //  air fair = variable
    //  car rental = car rental
    //  parking fees = 6
    //  taxi fees = 10
    //  hotel = 90
    //  food = variable
    //  gas = variable
    //  conference = variable
    //  calculate total
    //  total expense (running total) + days * 106
    //  days *

    printf("Weclome to \"TERC\" \nTravel Expense Reimbursement Calculator\n");
    int numOfDays = number_of_days();
    // int departureTime = get_departure_time();
    // int arrivalTime = get_arrival_time();
    // float totalMealsCost = get_totalMeal_cost(numOfDays);
    /***************************************************************************/
    float parkingFees = 0;
    int parkingDays = 0;
    float carRental = carRentalFees(carRental);
    float milageExpense;

    // Mile Fees Inputs
    if (carRental == 0)
    {
        milageExpense = mileFees();
    }

    //-----
// Parking Fees Inputs
GET_PARKING:
    printf("\nEnter the number of days you used parking:");
    scanf("%d", &parkingDays);
    if (parkingDays > numOfDays)
    {
        printf("Please enter a correct numeber of days. You may not exceed %d days.", numOfDays);
        goto GET_PARKING;
    }

    if (parkingDays <= 0)
    {
        parkingFees = 0;
    }
    else
    {
        printf("\nEnter your total parking fees:");
        scanf("%f", &parkingFees);
        parkingFees = calculateParkingFees(parkingFees, parkingDays);
    }
    ///-------
    // Prints the Car Fees
    printCar(carRental, milageExpense, parkingFees);

    // departure time?
    // return home time?
    // airFair = airfair(airfair);

    return 0;
}