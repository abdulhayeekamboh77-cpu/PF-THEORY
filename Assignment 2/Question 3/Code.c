/*Programmer: Abdul Hayee Kamboh
Program: Greenhouse Temperature Monitoring System
Roll No: 26K-0026
Section: BSAI-1A*/

#include <stdio.h>
void init(float grid[][100], int r, int c); // function prototype types)
void display(float grid[][100], int r, int c);
float analysis(float row[], int c, int sensor_number);
int max_avg(float avgs[], int r);

int main()
{
    float grid[20][100];
    float avgs[20];
    int r, c, k = 0, best;
    printf("Enter number of sensors: ";       // input senor and reading limits

    scanf("%d", &r);
    printf("Enter number of hourly readings: ");
    scanf("%d", &c);

    // Validate bounds for sensors and readings
    if (r < 1 || r > 20 || c < 1 || c > 100)
    {
        printf("Invalid input.\n");
        return 1;
    }

    init(grid, r, c);
    display(grid, r, c);
    printf("\n");

    // ---------- 3. ANALYZE EACH SENSOR DATA ----------
    while (k < r) 
    {
        avgs[k] = analysis(grid[k], c, k + 1);
        k++;
    }

    // ---------- 4. GENERATE FINAL REPORT ----------
    best = max_avg(avgs, r);
    printf("\n===== Final Report =====\n");
    printf("Highest average: Sensor %d (%.2f)\n", best, avgs[best - 1]);

    return 0;
}

// ---------- FUNCTION: INITIALIZE GRID ----------
// Populates the 2D array with temperature readings for each sensor
void init(float grid[][100], int r, int c)
{
    int row = 0, col;
    while (row < r)
    {
        printf("\nFOR SENSOR %d\n", row + 1);
        col = 0;
        while (col < c)
        {
            printf("Enter temperature reading for hour %d: ", col + 1);
            scanf("%f", &grid[row][col]);
            col++;
        }
        row++;
    }
}

// ---------- FUNCTION: DISPLAY GRID ----------
// Prints out all sensor readings in a structured format
void display(float grid[][100], int r, int c)
{
    int row = 0, col;
    while (row < r)
    {
        printf("\nSensor %d:", row + 1);
        col = 0;
        while (col < c)
        {
            printf(" %.2f", grid[row][col]);
            col++;
        }
        row++;
    }
}

// ---------- FUNCTION: ANALYSIS ----------
// Analyzes one sensor, prints its report, and returns its average temperature
float analysis(float row[], int c, int sensor_number)
{
    int i;
    float sum = 0, avg, high, low;
    int critical = 0, warning = 0;
    int start = -1;     /* index where current hot run began (-1 = no run) */
    int longest = 0;

    // Calculate total sum of temperatures
    for (i = 0; i < c; i++)
        sum += row[i];
    avg = sum / c;

    // Find highest temperature
    high = row[0];
    for (i = 1; i < c; i++)
        if (row[i] > high)
            high = row[i];

    // Find lowest temperature
    low = row[0];
    for (i = 1; i < c; i++)
        if (row[i] < low)
            low = row[i];

    // Calculate critical, warning counts and longest streak >= 35
    for (i = 0; i < c; i++)
    {
        critical += (row[i] >= 40);
        warning += (row[i] >= 35 && row[i] < 40);

        if (row[i] >= 35)
        {
            if (start == -1)
                start = i;
            if (i - start + 1 > longest)
                longest = i - start + 1;
        }
        else
        {
            start = -1;
        }
    }

    // Print individual sensor report
    printf("\n\n===== Report for Sensor %d =====\n", sensor_number);
    printf("Total    : %.2f\n", sum);
    printf("Average  : %.2f\n", avg);
    printf("Highest  : %.2f\n", high);
    printf("Lowest   : %.2f\n", low);
    printf("Critical : %d\n", critical);
    printf("Warning  : %d\n", warning);
    printf("Longest streak >= 35 : %d hour(s)\n", longest);

    return avg;
}

// ---------- FUNCTION: MAX AVERAGE FINDER ----------
// Returns the sensor number (1-based) with the highest average temperature
int max_avg(float avgs[], int r)
{
    int i = 0;
    float top = avgs[0];

    /* First find the biggest average value */
    for (i = 1; i < r; i++)
        if (avgs[i] > top)
            top = avgs[i];

    /* Then find which sensor corresponds to that average */
    i = 0;
    while (avgs[i] != top)
        i++;

    return i + 1;
}
