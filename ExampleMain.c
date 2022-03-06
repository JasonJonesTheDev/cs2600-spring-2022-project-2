/*
* CS2600 Project 2
* Functions written by @Casey Merritt
*/

#include <stdio.h>

/* Prototypes */
//you may need to add these
float airfare();
float registrationFees();
float hotelFees(int numOfDays);
float amountSaved(float allowable, float total);
float amountExcess(float allowable, float total);

int main(){
    //These should be declared already in your main
    float totalExpense;
    float totalAlloableExpense;
    float outOfPocket;
    float unUsedFundes;

    int numOfDays;

    float airFair;
    float registrationFees;
    float hotelExpenses;
    ///////////////////////////////////

    //Do this to get input and save values
    airFair = airfare();
    registrationFees = registrationFees();
    hotelExpenses = hotelFees(numOfDays);//have to pass days here

    //add these values to total maybe like this
    totalExpense += airFair;
    totalExpense += registrationFees;
    totalExpense += hotelExpenses;
    ///////////////////////////////////////


    //Do this at the end after all the calculations are done
    if(totalExpense > totalAlloableExpense){//checking if total expense is greater than allowable

        outOfPocket = amountExcess(totalAlloableExpense, totalExpense);//get difference

    }else if(totalExpense < totalAlloableExpense){//checking if total expense is less than allowable

        unUsedFundes = amountSaved(totalAlloableExpense, totalExpense);//get difference

    }else{
        unUsedFundes = amountSaved(totalAlloableExpense, totalExpense);
    }
}

/* Asks user for total airfare cost and returns that value*/
float airfare() {
    float airfare;
    int cont = 1;
 
    while (cont == 1) {
        printf("Enter RoundTrip Airfare: ");
        scanf("%f", &airfare);
 
        if(airfare < 0) {//checking for positive values only
            printf("\n");
            printf("Value must be greater than 0, try again\n");
            printf("\n");
        }else {
            cont = 0;
        }
    }
 
    return airfare;
}

/* Asks user for total registration cost and returns that value */
float registrationFees() {
    int cont = 1;
    float registrationCost;
   
    while (cont == 1) {
        printf("Enter total amount of registration fees: ");
        scanf("%f", &registrationCost);
 
        if (registrationCost < 0) {//checking to make sure only positive values are accepted
            printf("\n");
            printf("Value must be greater than 0, try again\n");
            printf("\n");
        }
        else {
            cont = 0;
        }
    }
 
    return registrationCost;
}

/* Asks user for hotel daily rate and calculate total cost*/
float hotelFees(int days) {
    float hotelFees;
    int cont = 1;
 
    while (cont) {
        printf("Enter Hotel Cost Per Day: ");
        scanf("%f", &hotelFees);
 
        if (hotelFees < 0) {//checking to make sure positive values only are accepted
            printf("\n");
            printf("Value must be greater than 0, try again\n");
            printf("\n");
        }
        else {
            cont = 0;
        }
    }
 
    return (hotelFees * days);
}

/* 
* Calculates the difference between allowable trip amount and total trip amount
* Function should only be called if total is greater than allowable otherwise return value will be invalid
*/
float amountSaved(float allowable, float total){
 
    if(total > allowable){
        printf("Something is broken");//this function should not be called if the total is greater than allowable call the excess function instead
        return -1;
    }else if(total == allowable){
        printf("the trip cost is equal to the allowable trip cost");
        return 0;
    }else{
        return (allowable - total);
    }
 
}

/* 
* Calculates the difference between total trip amount and allowable trip amount
* Function should only be called if total is less than allowable otherwise return value will be invalid
*/
float amountExcess(float allowable, float total){

    if(total < allowable){
        printf("Something is broken");//this function should not be called if the total is less than allowable, call the saved function instead
        return -1;
    }else if(total == allowable){
        printf("the trip cost is equal to the allowable trip cost");
        return 0;
    }else{
        return (total - allowable);
    }
 
}