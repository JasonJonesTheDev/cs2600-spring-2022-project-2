#include "header.h"

float mealLogic(int numOfDays, int departureTime, int arrivalTime)
{
    float total = 0;
    float breakfast = 0;
    float lunch = 0;
    float dinner = 0;

    int cont = 1;

    /* First Day Checker*/
    printf("-- Day 1 --\n");
    while (cont == 1)
    {
        if (departureTime < 7)
        {
            printf("Enter Breakfast cost: $");
            scanf("%f", &breakfast);
            printf("Enter Lunch Cost: $");
            scanf("%f", &lunch);
            printf("Enter Dinner Cost: $");
            scanf("%f", &dinner);

            if (dinner > 0 && lunch > 0 && breakfast > 0)
            {
                total += (lunch + dinner + breakfast);
                cont = 0;
            }
            else
            {
                printf("Invalid values must be greater than 0\n");
            }
        }
        else if (departureTime >= 7 && departureTime < 12)
        {
            printf("Enter Lunch Cost: $");
            scanf("%f", &lunch);
            printf("Enter Dinner Cost: $");
            scanf("%f", &dinner);

            if (dinner > 0 && lunch > 0)
            {
                total += (lunch + dinner);
                cont = 0;
            }
            else
            {
                printf("Invalid values must be greater than 0\n");
            }
        }
        else if (departureTime >= 12 && departureTime < 18)
        {
            printf("Enter Dinner Cost: $");
            scanf("%f", &dinner);

            if (dinner > 0)
            {
                total += (dinner);
                cont = 0;
            }
            else
            {
                printf("Invalid values must be greater than 0\n");
            }
        }
        else
        {
            printf("No eligible meals for day 1");
            cont = 0;
        }
    }

    // all normal days
    int mealindex = (numOfDays - 2);
    total += dailyMealsAdder(mealindex);

    /*Last Day Checker*/
    cont = 1;
    printf("-- Day %d --\n", numOfDays);
    while (cont == 1)
    {
        if (arrivalTime >= 8 && arrivalTime < 13)
        {
            printf("Enter Breakfast cost: $");
            scanf("%f", &breakfast);

            if (breakfast > 0)
            {
                total += (breakfast);
                cont = 0;
            }
            else
            {
                printf("Invalid values must be greater than 0\n");
            }
        }
        else if (arrivalTime >= 13 && arrivalTime < 19)
        {
            printf("Enter Breakfast cost: $");
            scanf("%f", &breakfast);
            printf("Enter Lunch Cost: $");
            scanf("%f", &lunch);

            if (lunch > 0 && breakfast > 0)
            {
                total += (lunch + breakfast);
                cont = 0;
            }
            else
            {
                printf("Invalid values must be greater than 0\n");
            }
        }
        else if (arrivalTime >= 19)
        {
            printf("Enter Breakfast cost: $");
            scanf("%f", &breakfast);
            printf("Enter Lunch Cost: $");
            scanf("%f", &lunch);
            printf("Enter Dinner Cost: $");
            scanf("%f", &dinner);

            if (dinner > 0 && lunch > 0 && breakfast > 0)
            {
                total += (lunch + dinner + breakfast);
                cont = 0;
            }
            else
            {
                printf("Invalid values must be greater than 0\n");
            }
        }
        else
        {
            printf("No eligible meals for day %d", numOfDays);
        }
    }
    return total;
}

/*Calculator for normal day*/
float dailyMealsAdder(int numOfDays)
{
    float breakfast = 0;
    float lunch = 0;
    float dinner = 0;
    float total = 0;

    for (int i = 0; i < numOfDays; i++)
    {
        int cont = 1;
        while (cont == 1)
        {
            printf("-- Day %d --\n", (i + 2));
            printf("Enter Breakfast cost: $");
            scanf("%f", &breakfast);
            printf("Enter Lunch Cost: $");
            scanf("%f", &lunch);
            printf("Enter Dinner Cost: $");
            scanf("%f", &dinner);

            if (breakfast < 0 || lunch < 0 || dinner < 0)
            {
                printf("Please Enter Values Of At Least 0\n");
            }
            else
            {
                total += (breakfast + lunch + dinner);
                cont = 0;
            }
        }
    }
    return total;
}

/* Calculates Total Allowable Based On Values Given*/
float totalAllowableCalc(int days, float airfare, float carRentalFees, float milesExpense, float registrationFees, int departure, int arrival)
{
    float totalAllowable = 0;

    totalAllowable += airfare;
    totalAllowable += carRentalFees;
    totalAllowable += milesExpense;
    totalAllowable += (days * 6);  // parking fees
    totalAllowable += (days * 10); // taxi fees
    totalAllowable += registrationFees;
    totalAllowable += (days * 90);                              // hotel fees
    totalAllowable += ((days * 9) + (days * 12) + (days * 16)); // meal cost max

    if (departure < 7)
    {
        // lunch breakfast and dinner
    }
    else if (departure >= 7 && departure < 12)
    {
        // lunch and dinner
        totalAllowable -= (9);
    }
    else if (departure >= 12 && departure < 18)
    {
        // dinner only
        totalAllowable -= (9 + 12);
    }
    else
    {
        // none
        totalAllowable -= (9 + 12 + 16);
    }

    if (arrival >= 8 && arrival < 13)
    {
        // only breakfast
        totalAllowable -= (12 + 16);
    }
    else if (arrival >= 13 && arrival < 19)
    {
        // lunch and breakfast
        totalAllowable -= (16);
    }
    else if (arrival >= 19)
    {
        // lunch breakfast and dinner
    }
    else
    {
        // none
        totalAllowable -= (9 + 12 + 16);
    }
    return totalAllowable;
}
