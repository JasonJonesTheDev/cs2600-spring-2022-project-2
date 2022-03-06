#include <stdio.h>
//#include "car.c"


// Print Car Fees
int printCar(float carRental, int milesDriven, float parkingFees, int parkingDays) {
    printf("\nCar Rental Fees: %.2lf\n", carRentalFees(carRental));
    printf("Miles Costs: %.2lf\n", mileFees(milesDriven));
    printf("ParkingFees: %.2lf\n", calculateParkingFees(parkingFees, parkingDays));

    return 0;
}