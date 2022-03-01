#include <stdio.h>


// Variables
// Total days traveled
extern const int numOfDays;
// The time of departure on the first day of the trip, 
// and the time of arrival back home on the last day of the trip.
extern int departureTime;
extern int arrivalTime;

// The amount of any round-trip airfare 
extern float airFair;

// The amount of any car rentals 
extern float carRental;

// Miles driven, if a private vehicle was used. 
// Calculate the vehicle expense as $0.27 per mile driven 
extern int milesDriven;
extern float milesReimbers;


// Parking fees (The company allows up to $6 per day. 
// Anything more than this must be paid by the employee.) 
extern float parkingFees;

// Taxi fees, if a taxi was used anytime during the trip 
// (The company allows up to $10 per day, for each day a taxi was used. 
// Anything more than this must be paid by the employee.) 
extern float taxiFees;

// Conference or seminar registration fees 
extern float registraionFees;
 
// Hotel expenses (The company allows up to $90 per night for lodging. 
// Anything more than this must be paid by the employee.) 
extern float hotelExpense;

// The amount of each meal eaten and total meal cost after compensation.
extern float breakfast;
extern float lunch;
extern float dinner;
extern float totalMealsCost;

// reference to file access methods
// https://stackoverflow.com/questions/1045501/how-do-i-share-variables-between-different-c-files