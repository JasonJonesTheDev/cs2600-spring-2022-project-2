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
    printf("\nrental: %d\n", carRental);
    float rentalCost;
    rentalCost = carRental;

    if (carRental <= 0) {
        carRental = 0;
    }

    return rentalCost;
}

float mileFees(int milesDriven) {
    float milesReimbers;
    printf("\nmiles: %d\n", milesDriven);
    if (milesDriven <= 0) {
        milesReimbers = 0;
    } else {
        milesReimbers = (milesDriven * 0.27);
    }

    if(milesReimbers <= 0) {
        milesReimbers = 0;
    }

    return milesReimbers;
}

float calculateParkingFees(float parkingFees, int parkingDays) {
    if (parkingDays <= 0) {
        parkingFees = 0;
    } if (parkingFees <= 0) {
        parkingFees = 0;
    } else {
        parkingFees = parkingFees - (6 * parkingDays);
    }

    if (parkingFees < 0) {
        parkingFees = 0;
    }
    
    return parkingFees;
}


/* **This is used in an other file test.c to check my code on my local side */
// void main() {
//     float carRental;
//     int milesDriven;
//     float parkingFees;
//     int parkingDays;
//     char yesOrNo[1];

//     do{
//         printf("\nDid you rent a car?(y or n):");
//         scanf("%s", yesOrNo);
//         if(yesOrNo, "y") {
//         printf("\nEnter any car rental fees:");
//         scanf("%f", &carRental);
//         } else {
//             carRental = 0;
//         }

//         printf("\nEnter your total miles driven:");
//         scanf("%d", &milesDriven);

//         printf("\nEnter the number of days you used parking:");
//         scanf("%d", &parkingDays);
//         if (parkingDays <= 0) {
//             parkingFees = 0;
//         } else {
//             printf("\nEnter your total parking fees:");
//             scanf("%f", &parkingFees);
//         }
//     } while(carRental < 0 && milesDriven < 0 && parkingDays < 0 && parkingFees < 0);
//     printf("\nrent main: %f\n", carRental);

//     printCar(carRental, milesDriven, parkingFees, parkingDays);
// }
