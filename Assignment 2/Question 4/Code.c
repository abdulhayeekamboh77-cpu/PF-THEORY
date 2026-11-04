/*Programmer: Abdul Hayee Kamboh
Program: Bakery Festival Sales Management System
Roll No: 26K-0026
Section: BSAI-1A*/
#include <stdio.h>

/* Function 1: asks for number of festival days until it is between 1 and 7 */
int getValidDays()
{
    int days;

    printf("Enter number of festival days (1-7): ");
    scanf("%d", &days);

    /* keep asking until the value is valid */
    while (days < 1 || days > 7)
    {
        printf("Invalid! Days must be between 1 and 7. Enter again: ");
        scanf("%d", &days);
    }

    return days;
}

/* Function 2: processes one day, displays its summary, returns total sales */
float calculateDailySales(int dayNumber)
{
    int orders, i;
    float amount, total = 0, highest = 0, average;

    printf("\n--- Day %d ---\n", dayNumber);
    printf("Enter number of orders: ");
    scanf("%d", &orders);

    for (i = 1; i <= orders; i++)
    {
        printf("Enter amount of order %d (Rs.): ", i);
        scanf("%f", &amount);

        /* amount must be greater than zero, ask again for the SAME order */
        while (amount <= 0)
        {
            printf("Invalid! Amount must be greater than 0. Enter order %d again: ", i);
            scanf("%f", &amount);
        }

        total = total + amount;       /* add to day's total */

        if (amount > highest)         /* track highest order of the day */
            highest = amount;
    }

    average = total / orders;         /* orders is at least 1 */

    printf("\nDay %d Summary:\n", dayNumber);
    printf("Total sales   : Rs. %.2f\n", total);
    printf("Average order : Rs. %.2f\n", average);
    printf("Highest order : Rs. %.2f\n", highest);

    return total;
}

/* Function 3: returns the day number (starting from 1) with highest sales */
int findHighestSalesDay(float dailySales[], int numberOfDays)
{
    int i, bestDay = 0;               /* index of best day so far */

    for (i = 1; i < numberOfDays; i++)
    {
        /* ">" (not ">=") keeps the earliest day when sales are equal */
        if (dailySales[i] > dailySales[bestDay])
            bestDay = i;
    }

    return bestDay + 1;               /* day numbers start from 1 */
}

/* Function 4: prints one * for every complete Rs. 100 of daily sales */
void displayBarChart(float dailySales[], int numberOfDays)
{
    int i, j, stars;

    printf("\n===== Daily Sales Bar Chart (* = Rs. 100) =====\n");

    for (i = 0; i < numberOfDays; i++)
    {
        stars = (int)(dailySales[i] / 100);   /* ignores the part below 100 */

        printf("Day %d: ", i + 1);
        for (j = 0; j < stars; j++)
            printf("*");
        printf("\n");
    }
}

int main()
{
    float dailySales[7];              /* total sales of each day */
    float festivalTotal = 0;
    int days, i, bestDay;

    days = getValidDays();

    /* process every day and store its returned total in the array */
    for (i = 0; i < days; i++)
    {
        dailySales[i] = calculateDailySales(i + 1);
        festivalTotal = festivalTotal + dailySales[i];
    }

    bestDay = findHighestSalesDay(dailySales, days);

    printf("\n===== Festival Sales Summary =====\n");
    printf("Total sales of festival : Rs. %.2f\n", festivalTotal);
    printf("Day with highest sales  : Day %d (Rs. %.2f)\n", bestDay, dailySales[bestDay - 1]);

    displayBarChart(dailySales, days);

    return 0;
}
