#include <stdio.h>
//#include "car.c"
//#include "printCar.c"
// *NOTE TO CODE PARTNERS: you can put this code into the scans of main however you want to do it.
/* **This is used to check my code on my local side as my local main.c file */
void main() {
    // Parameter Variables for Car.c
    float carRental;
    int milesDriven;
    float parkingFees;
    int parkingDays;
    char yesOrNo[1];

    // Asks the user for the inputs needed for car fees
    do{
        // Car Rental Fees Inputs
        printf("\nDid you rent a car?(y or n):");
        scanf("%s", yesOrNo);
        if(yesOrNo, "y") {
        printf("\nEnter any car rental fees:");
        scanf("%f", &carRental);
        } else {
            carRental = 0;
        }

        // Mile Fees Inputs
        printf("\nEnter your total miles driven:");
        scanf("%d", &milesDriven);

        // Parking Fees Inputs
        printf("\nEnter the number of days you used parking:");
        scanf("%d", &parkingDays);
        if (parkingDays <= 0) {
            parkingFees = 0;
        } else {
            printf("\nEnter your total parking fees:");
            scanf("%f", &parkingFees);
        }
    } while(carRental < 0 && milesDriven < 0 && parkingDays < 0 && parkingFees < 0);

    // Prints the Car Fees
    printCar(carRental, milesDriven, parkingFees, parkingDays);
}
