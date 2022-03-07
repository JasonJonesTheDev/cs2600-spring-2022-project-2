#include <stdio.h>
#include "header.h"
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
float carRentalFees(float carRental)
{
    // Car Rental Fees Inputs
    printf("\nDid you rent a car?(y or n):");
    char yesOrNo[6];
    scanf("%s", &yesOrNo);
    if (yesOrNo[0] == 'y')
    {
    GET_RENTALCOST:
        printf("\nEnter any car rental fees:");
        scanf("%f", &carRental);
        if (carRental <= 0 || carRental > 1000)
        {
            printf("PLease enter a valid amount...");
            goto GET_RENTALCOST;
        }
    }
    else
    {
        carRental = 0;
        return carRental;
    }
    if (carRental <= 0)
    { // error handeling for negatives
        printf("Please enter a positive number");
        carRental = 0;
    }

    return carRental;
}

/* Mile Fees Function */
float mileFees()
{
    printf("\nEnter your total miles driven:");
    int milesDriven = 0;
    scanf("%d", &milesDriven);

    float milesReimbers = 0; // Calculated mile gas costs

    // Calculate Mile Fees
    if (milesDriven <= 0)
    { // check for 0 or < 0
        milesReimbers = 0;
    }
    else
    { // calculation with miles driven
        milesReimbers = (milesDriven * 0.27);
    }

    return milesReimbers;
}
/* Parking Fees Function */
float calculateParkingFees(float parkingFees, int parkingDays)
{
    // Calculate Parking Fees
    if (parkingDays <= 0)
    { // check for 0 or < 0 in days
        parkingFees = 0;
    }
    if (parkingFees <= 0)
    { // check for 0 or < 0 in parking fees
        parkingFees = 0;
    }
    else
    { // calculation for parking fees
        parkingFees = parkingFees - (6 * parkingDays);
    }

    // Check for Negative
    if (parkingFees < 0)
    { // recheck for negative
        parkingFees = 0;
    }

    return parkingFees;
}

// Calculate Taxi Fees

// int calculateTaxiFees(char taxiUse[10], double taxiFee, int taxiDays)
// { // company TAXI_COVERED_PER_DAY = 10

//     if (taxiUse, 'y')
//     {

//         taxiFee = taxiFee - (TAXI_COVERED_PER_DAY * taxiDays);

//         if (taxiFee < 0)
//         {

//             taxiFee = 0;
//         }
//     }

//     return taxiFee;
// }