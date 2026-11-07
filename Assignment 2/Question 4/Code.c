/*Programmer: Abdul Hayee Kamboh
Program: Bakery Festival Sales Management System
Roll No: 26K-0026
Section: BSAI-1A*/

#include <stdio.h>

// ==========================================
// FUNCTION 1: GET VALID DAYS
// Asks the user for the number of festival days and validates 
// that the input lies strictly within the range of 1 to 7.
// ==========================================
int getValidDays()
{
    int days;

    // Prompt user to enter festival duration
    printf("Enter number of festival days (1-7): ");
    scanf("%d", &days);

    /* Keep asking in a loop until a valid range (1 to 7) is provided */
    while (days < 1 || days > 7)
    {
        printf("Invalid! Days must be between 1 and 7. Enter again: ");
        scanf("%d", &days);
    }

    return days;
}

// ==========================================
// FUNCTION 2: CALCULATE DAILY SALES
// Processes individual orders for a specific day, validates 
// order amounts, computes statistics, and returns the day's total sales.
// ==========================================
float calculateDailySales(int dayNumber)
{
    int orders, i;
    float amount, total = 0, highest = 0, average;

    // Display header for the current day being processed
    printf("\n--- Day %d ---\n", dayNumber);
    printf("Enter number of orders: ");
    scanf("%d", &orders);

    // Loop through each order for the current day
    for (i = 1; i <= orders; i++)
    {
        printf("Enter amount of order %d (Rs.): ", i);
        scanf("%f", &amount);

        /* Validate that order amount is strictly greater than zero */
        while (amount <= 0)
        {
            printf("Invalid! Amount must be greater than 0. Enter order %d again: ", i);
            scanf("%f", &amount);
        }

        total = total + amount;        /* Accumulate order amount to day's total */

        /* Track and update the highest single order amount for the day */
        if (amount > highest)          
            highest = amount;
    }

    // Calculate daily average order value (orders count is at least 1 here)
    average = total / orders;          

    // Print summary statistics for the completed day
    printf("\nTotal sales: Rs. %.2f\n", total);
    printf("Average order: Rs. %.2f\n", average);
    printf("Highest order: Rs. %.2f\n", highest);

    return total;
}

// ==========================================
// FUNCTION 3: FIND HIGHEST SALES DAY
// Iterates through the daily sales array to determine 
// which day generated the maximum total revenue.
// ==========================================
int findHighestSalesDay(float dailySales[], int numberOfDays)
{
    int i, bestDay = 0;                    /* Assume the first day has the max sales initially */

    // Loop through all recorded festival days
    for (i = 1; i < numberOfDays; i++)
    {
        /* Strictly greater '>' operator ensures the earliest day is retained in case of a tie */
        if (dailySales[i] > dailySales[bestDay])
            bestDay = i;
    }

    return bestDay + 1;                    /* Convert 0-based array index back to 1-based day number */
}

// ==========================================
// FUNCTION 4: DISPLAY BAR CHART
// Generates a visual text-based bar chart representing 
// daily sales where each asterisk (*) corresponds to Rs. 100.
// ==========================================
void displayBarChart(float dailySales[], int numberOfDays)
{
    int i, j, stars;

    // Print header for the bar chart section
    printf("\n===== DAILY SALES BAR CHART =====\n");

    // Loop through each day to calculate and print its corresponding stars
    for (i = 0; i < numberOfDays; i++)
    {
        // Typecast division to integer to find how many complete hundreds exist
        stars = (int)(dailySales[i] / 100);    

        printf("Day %d: ", i + 1);
        
        // Print an asterisk for every complete Rs. 100 of sales
        for (j = 0; j < stars; j++)
            printf("*");
            
        printf(" (Rs. %.2f)\n", dailySales[i]);
    }
}

// ==========================================
// MAIN FUNCTION
// Controls the core program flow, coordinates function calls, 
// maintains festival totals, and presents the final summary report.
// ==========================================
int main()
{
    float dailySales[7];                    /* Array to store total sales for each festival day */
    float festivalTotal = 0;            /* Accumulator for total festival revenue */
    int days, i, bestDay;

    // Step 1: Input and validate total festival duration
    days = getValidDays();

    // Step 2: Process sales for each day sequentially using a loop
    for (i = 0; i < days; i++)
    {
        dailySales[i] = calculateDailySales(i + 1);
        festivalTotal = festivalTotal + dailySales[i]; // Add daily total to grand total
    }

    // Step 3: Identify the top-performing sales day
    bestDay = findHighestSalesDay(dailySales, days);

    // Step 4: Display the comprehensive festival summary report
    printf("\n===== FESTIVAL SUMMARY =====\n");
    printf("Total festival sales: Rs. %.2f\n", festivalTotal);
    printf("Day with highest sales: Day %d\n", bestDay);
    printf("Highest daily sales: Rs. %.2f\n", dailySales[bestDay - 1]);

    // Step 5: Render visual bar chart for analytical overview
    displayBarChart(dailySales, days);

    return 0;
}
