#include <header.h>  

int main()
{ 
// Variables
// Total days traveled
const int numDay;
// The time of departure on the first day of the trip, 
// and the time of arrival back home on the last day of the trip.
int departure;
int arrival;

// The amount of any round-trip airfare 
float airFair;

// The amount of any car rentals 
float carRental;

// Miles driven, if a private vehicle was used. 
// Calculate the vehicle expense as $0.27 per mile driven 
int milesDriven;
float milesReimbers;


// Parking fees (The company allows up to $6 per day. 
// Anything more than this must be paid by the employee.) 
float parkingFees;

// Taxi fees, if a taxi was used anytime during the trip 
// (The company allows up to $10 per day, for each day a taxi was used. 
// Anything more than this must be paid by the employee.) 
float taxiFees;

// Conference or seminar registration fees 
float registraionFees;
 
// Hotel expenses (The company allows up to $90 per night for lodging. 
// Anything more than this must be paid by the employee.) 
float hotelExpense;

// The amount of each meal eaten and total meal cost after compensation.
float breakfast;
float lunch;
float dinner;
float totalMealsCost;
    
    printf("Weclome to  \"TERC\" \n Travel Expense Reimbursement Calculator");

    return 0;
}