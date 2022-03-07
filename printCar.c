#include <stdio.h>
//#include "car.c"


// Print Car Fees
int printCar(float carRental, float milesReimbursed, float parkingFees) {
    printf("\nCar Rental Fees: %.2lf\n", carRental);
    printf("Miles Costs: %.2lf\n", milesReimbursed);
    printf("ParkingFees: %.2lf\n", parkingFees);

    return 0;
}