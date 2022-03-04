#include <stdio.h>
#include "car.c"

int printCar(float carRental, int milesDriven, float parkingFees, int parkingDays) {
     printf("\nCar Rental Fees: %lf\n", carRentalFees(carRental));
    printf("Miles Costs: %lf\n", mileFees(milesDriven));
    printf("ParkingFees: %lf\n", calculateParkingFees(parkingFees, parkingDays));

    return 0;
}