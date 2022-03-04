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

void AskUserForCarInputs() {
    float carRental;
    int milesDriven;
    float parkingFees;
    int parkingDays;
    printf("Enter any car rental fees:");
    scanf("%d\n", &carRental);
    printf("Enter your total miles driven:");
    scanf("%d\n", &milesDriven);
    printf("Enter the number of days you used parking:");
    scanf("%d\n", &parkingDays);
    if (parkingDays <= 0) {
        parkingFees = 0;
    } else {
        printf("Enter your total parking fees:");
        scanf("%d\n", &parkingFees);
    }
}

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

/* **This is used to check my code on my local side */
// void main(float carRental, int milesDriven, float parkingFees, int parkingDays) {
//     AskUserForCarInputs();
//     printf("Car Rental Fees: %d\n", carRentalFees(carRental));
//     printf("Miles Costs: %d\n", mileFees(milesDriven));
//     printf("ParkingFees: %d\n", calculateParkingFees(parkingFees, parkingDays));
// }