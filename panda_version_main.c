#include "suhuan_draft.c"




void panda_version()
{
    // Variables
    // The running total allowable expenses for the trip
   // float totalExpense;
    // The Rrunning total expenses incurred by the businessperson,
   // float totalAlowableExpense;


    // The excess that must be reimbursed by the businessperson, if any.
  //  float outOfPocket;
    // The amount saved by the company/business person if the expenses
    // were under the total allowed.
  //  float unUsedFunds;

  //  float maximumFunds;

    // air fair = variable
    // car rental = car rental
    // parking fees = 6
    // taxi fees = 10
    // hotel = 90
    // food = variable
    // gas = variable
    // conference = variable
    // 
    // 

    // calculate total
    // total expense (running total) + days * 106 
    // days * 




    // Total days traveled
    const int numOfDays = numDays;


    // The time of departure on the first day of the trip,
    // and the time of arrival back home on the last day of the trip.
    int departureTime = get_departure_time();
    int arrivalTime = get_arrival_time();


    // The amount of any round-trip airfare
   // float airFair;

    // The amount of any car rentals
  //  float carRental;

    // Miles driven, if a private vehicle was used.
    // Calculate the vehicle expense as $0.27 per mile driven
   // int milesDriven;
    // float milesReimbers;

    // Parking fees (The company allows up to $6 per day.
    // Anything more than this must be paid by the employee.)
   // float parkingFees;

    // Taxi fees, if a taxi was used anytime during the trip
    // (The company allows up to $10 per day, for each day a taxi was used.
    // Anything more than this must be paid by the employee.)
    //float taxiFees;

    // Conference or seminar registration fees
    //float registraionFees;

    // Hotel expenses (The company allows up to $90 per night for lodging.
    // Anything more than this must be paid by the employee.)
    //float hotelExpense;

    // The amount of each meal eaten and total meal cost after compensation.
//    float breakfast;
//    float lunch;
//    float dinner;

    float totalMealsCost = get_totalMeal_cost(numOfDays);

    printf("Welcome to  \"TERC\" \n Travel Expense Reimbursement Calculator\n");


}
