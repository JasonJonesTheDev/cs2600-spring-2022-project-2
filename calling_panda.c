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
//
//
//    float breakfast = 0.0;
//    float lunch = 0.0;
//    float dinner = 0.0;

    // The amount of each meal eaten and total meal cost after compensation.
    float totalMealsCost = call_by_main(numOfDays, departureTime, arrivalTime);

    return 0;
}
