#include <stdio.h>
/* Outline
    all vars
    float carRental;
    int milesDriven;
    float milesReimbers;
    float parkingFees;
    float taxiFees;

    1. amount of car rentals
    2. miles driven
    3. parking fees
    4. taxi fees
*/

float carRentalFees(float carRental) {
    carRental = carRental;

    return carRental;
}

float mileFees(int milesDriven) {
    float milesReimbers;
    milesDriven = milesDriven;
    milesReimbers = (milesDriven * 0.27);

    return milesReimbers;
}

float calculateParkingFees(float parkingFees, int parkingDays) {
    parkingDays = parkingDays;
    parkingFees = parkingFees - (6 * parkingDays);
    
    if (parkingFees <= 0) {
        parkingFees = 0;
    }
    
    return parkingFees;
}

void printCar(float carRental, int milesDriven, float parkingFees, int parkingDays) {
    printf("\nCar Rental Fees: %d\n", carRentalFees(carRental));
    printf("Miles Costs: %d\n", mileFees(milesDriven));
    printf("ParkingFees: %d\n", calculateParkingFees(parkingFees, parkingDays));
}

/* **This is used to check my code on my local side */
void main() {
    float carRental;
    int milesDriven;
    float parkingFees;
    int parkingDays;
    char yesOrNo;

    do{
        printf("\nDid you rent a car?(y or n):");
        scanf("%s", yesOrNo);
        if(yesOrNo, "y") {
            printf("\nEnter any car rental fees:");
            scanf("%d\n", &carRental);
        } else {
            carRental = 0;
        }

        printf("\nEnter your total miles driven:");
        scanf("%d\n", &milesDriven);

        printf("\nEnter the number of days you used parking:");
        scanf("%d\n", &parkingDays);
        if (parkingDays <= 0) {
            parkingFees = 0;
        } else {
            printf("\nEnter your total parking fees:");
            scanf("%d\n", &parkingFees);
        }
    } while(carRental < 0 && milesDriven < 0 && parkingDays < 0 && parkingFees < 0);

    printCar(carRental, milesDriven, parkingFees, parkingDays);
}