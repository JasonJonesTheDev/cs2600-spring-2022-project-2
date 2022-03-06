#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// #define numDays number_of_days ()
#define numDays number_of_days()

/***************  prototype ***************/
int number_of_days();
int get_time();
void get_mealCost(float *breakfast, float *lunch, float *dinner);
struct meal_cost *firstDay();
void firstDay_mealRule(float breakfast, float lunch, float dinner, float *allow, float *extra);

int get_departure_time();
float total_mealCost(float breakfast_cost, float lunch_cost, float dinner_cost);
int get_arrival_time();
void lastDay_mealRule(float breakfast, float lunch, float dinner, float *allow, float *extra);
void otherDay_mealRule(float breakfast, float lunch, float dinner, float *allow, float *extra);

void otherDay_mealRule(float breakfast, float lunch, float dinner, float *allow, float *extra);
float get_totalMeal_cost(int numOfDays);

void FirstDay(int *ptr_const);
void LastDay(struct meal_cost *lastDay);
void commonDay(struct meal_cost *commonDay);
int printCar(float carRental, int milesDriven, float parkingFees);
float carRentalFees(float carRental);
float mileFees();
float calculateParkingFees(float parkingFees, int parkingDays);

// // static float get_totalMeal_cost(int number_of_days);
// // Variables
// // The running total allowable expenses for the trip
// extern float totalExpense;
// // The running total expenses incurred by the traveler,
// extern float totalAlowableExpense;
// // The excess that must be reimbursed by the traveler, if any.
// extern float outOfPocket;
// // The amount saved by the company/business person if the expenses
// // were under the total allowed.
// extern float unUsedFunds;
// // Total possible amount traveler can receive
// extern float maximumFunds;
// // Total days traveled
// extern int numOfDays;
// // The time of departure on the first day of the trip,
// // and the time of arrival back home on the last day of the trip.
// extern int departureTime;
// extern int arrivalTime;
// // The amount of any round-trip airfare
// extern float airfair;
// // The amount of any car rentals
// extern float carRental;
// // Miles driven, if a private vehicle was used.
// // Calculate the vehicle expense as $0.27 per mile driven
// extern int milesDriven;
// extern float milesReimbers;
// // Parking fees (The company allows up to $6 per day.
// // Anything more than this must be paid by the employee.)
// extern float parkingFees;
// // Taxi fees, if a taxi was used anytime during the trip
// // (The company allows up to $10 per day, for each day a taxi was used.
// // Anything more than this must be paid by the employee.)
// extern float taxiFees;
// // Conference or seminar registration fees
// extern float registrationFees;
// // Hotel expenses (The company allows up to $90 per night for lodging.
// // Anything more than this must be paid by the employee.)
// extern float hotelExpense;
// // The amount of each meal eaten and total meal cost after compensation.
// extern float breakfast;
// extern float lunch;
// extern float dinner;
// extern float totalMealsCost;
// reference to file access methods
// https://stackoverflow.com/questions/1045501/how-do-i-share-variables-between-different-c-files