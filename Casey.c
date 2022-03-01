/*
* CS2600 Project 2
* Functions written by @Casey Merritt
*/

#include <stdio.h>
 
 /* Function Declaration */
float airfare();
float registrationFees();
float hotelFees(int days);
float amountSaved(float allowable, float total);

/* Test Main For Function Testing */
int main(){

    //test 1
    float af = airfare();

    //test 2
    float rf = registrationFees();
    
    //test 3
    int days = 3;
    float hf = hotelFees(days);

    //test 4
    float allowabale = 1700;
    float total = 1400;
    float saved = amountSaved(allowabale, total);
    
    //check values
    printf("\n");
    printf("Airfare: %.2f\n", af);
    printf("Registration Fees: %.2f\n", rf);
    printf("Hotel Fees: %.2f\n", hf);
    printf("Saved: %.2f\n", saved);

    return 0;
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
* Function should only be called if total is less than allowable otherwise return value will be invalid
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

