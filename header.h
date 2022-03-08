#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/***************  function prototypes ***************/
int number_of_days();
int get_time();
int get_departure_time();
int get_arrival_time();
float mealLogic(int numOfDays, int departureTime, int arrivalTime);
float dailyMealsAdder(int numOfDays);
float totalAllowableCalc(int days, float airfare, float carRentalFees, float milesExpense, float registrationFees, int departure, int arrival);
void printTimes(int, int);
int printCar(float carRental, int milesDriven, float parkingFees);
float carRentalFees();
float mileFees();
float calculateParkingFees(int numOfDays);
float calculateTaxiFees(int numOfDays);
float airfare();
float conferenceFees();
float hotelFees(int numOfDays);
float amountSaved(float totalAlloableExpense, float totalExpense);
float amountExcess(float totalAllowableExpense, float totalExpense);
