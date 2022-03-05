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

/* Car Rental Fees Function */
float carRentalFees(float carRental) {
    float rentalCost; // used to hold carRental inside this function

    // Save Rental Cost
    rentalCost = carRental;

    // Check for Negative
    if (carRental <= 0) {// error handeling for negatives
        carRental = 0;
    }

    return rentalCost;
}

/* Mile Fees Function */
float mileFees(int milesDriven) {
    float milesReimbers; // Claculated mile gas costs

    // Calculate Mile Fees
    if (milesDriven <= 0) {// check for 0 or < 0
        milesReimbers = 0;
    } else { // calculation with miles driven
        milesReimbers = (milesDriven * 0.27);
    }

    // Check for Negative
    if(milesReimbers <= 0) { // recheck for negative
        milesReimbers = 0;
    }

    return milesReimbers;
}

/* Parking Fees Function */
float calculateParkingFees(float parkingFees, int parkingDays) {
    // Calculate Parking Fees
    if (parkingDays <= 0) {// check for 0 or < 0 in days
        parkingFees = 0;
    } if (parkingFees <= 0) { // check for 0 or < 0 in parking fees
        parkingFees = 0;
    } else { // calculation for parking fees
        parkingFees = parkingFees - (6 * parkingDays);
    }

    // Check for Negative
    if (parkingFees < 0) { // recheck for negative
        parkingFees = 0;
    }
    
    return parkingFees;
}