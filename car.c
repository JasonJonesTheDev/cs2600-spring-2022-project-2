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
float carRentalFees()
{
    float carRental = 0;
    // Car Rental Fees Inputs
    printf("Did you rent a car?(y or n): ");
    char yesOrNo[6];
    scanf("%s", &yesOrNo);
    if (yesOrNo[0] == 'y')
    {
    GET_RENTALCOST:
        printf("Enter any car rental fees: $");
        scanf("%f", &carRental);
        if (carRental <= 0 || carRental > 1000)
        {
            printf("Error: Please enter a valid amount...");
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
        printf("Error: Please enter a positive number");
        carRental = 0;
    }

    return carRental;
}

/* Mile Fees Function */
float mileFees()
{
    printf("Enter your total miles driven: ");
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
float calculateParkingFees(int numOfDays)
{
    float parkingFees;
    int parkingDays;
// Parking Fees Inputs
// Parking Days Scan
GET_PARKING_DAYS:
    printf("Enter the number of days you used parking: ");
    scanf("%d", &parkingDays);

    // Check Parking Days
    if (parkingDays > numOfDays || parkingDays < 0)
    {
        printf("Please enter a correct number of days. You may not exceed %d days.", numOfDays);
        parkingDays = 0;
        goto GET_PARKING_DAYS;
    }
    else
    {
        // Check for 0
        if (parkingDays = 0)
        {
            parkingFees = 0;
        }
        else
        {
        // Parking Fees Scan
        GET_PARKING:
            printf("Enter your total parking fees: $");
            scanf("%f", &parkingFees);

            // Check Parking Fees
            if (parkingFees < 0 || parkingFees > 1000)
            {
                printf("Error: Enter a valid amount of money...");
                parkingFees = 0;
                goto GET_PARKING;
            }
            else
            {
                // Calculate Parking Fees
                parkingFees = parkingFees - (6 * parkingDays);
            }
        }
    }

    return parkingFees;
}

// Calculate Taxi Fees

float calculateTaxiFees(int numOfDays)
{
    char taxiUse[10]; 
    float taxiFee = 0;
    int taxiDays = 0; 
    // Ask if taxi was used
    printf("Did you use a taxi on your trip?(y or n): ");
    scanf("%s", &taxiUse[0]);

    if (taxiUse[0] == 'y')
    {
    // Taxi Days Scan
    TAXI_FEE_DAYS:
        printf("How many days did you use a taxi?: ");
        scanf("%d", &taxiDays);

        // Check Taxi Days
        if (taxiDays > numOfDays || taxiDays < 0)
        {
            printf("Please enter a correct number of days. You may not exceed %d days.", numOfDays);
            taxiDays = 0;
            goto TAXI_FEE_DAYS;
        }
        else
        {
            // Check for 0
            if (taxiDays = 0)
            {
                taxiFee = 0;
            }
            else
            {
            // Taxi Fees Scan
            TAXI_FEES:
                printf("Enter your total taxi fees: $");
                scanf("%f", &taxiFee);

                // Check Taxi Fees
                if (taxiFee < 0 || taxiFee > 1000)
                {
                    printf("Error: Enter a realistic amount of money...");
                    taxiFee = 0;
                    goto TAXI_FEES;
                }
                else
                {
                    // Calculate Taxi Fees
                    taxiFee = taxiFee - (10 * taxiDays);
                }
            }
        }
    }

    return taxiFee;
}