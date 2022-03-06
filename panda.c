#include "panda_time.c"
#include "meal.c"

// calling suhuan's work on main
// display number of days
// ask the cost of each meal
// display the total allowable cost for the entire trip

int main()
{
    // Total days traveled
    const int numOfDays = numDays;


    // The time of departure on the first day of the trip,
    // and the time of arrival back home on the last day of the trip.
    int departureTime = get_departure_time();
    int arrivalTime = get_arrival_time();



    // The amount of each meal eaten and total meal cost after compensation.
    float *totalAllowableCost;

    float totalMealsCost = call_by_main(numOfDays, departureTime,
                                        arrivalTime,totalAllowableCost);


    printf("\n----------------\nTotal cost of the entire trip is $%.2f\n", totalMealsCost);
    printf("Total allowable cost of entire trip is $%.2f\n", (totalAllowableCost));

    float *hi = &(totalAllowableCost);
    printf("Total allowable cost of entire trip is $%.2f\n", hi);

    return 0;
}
