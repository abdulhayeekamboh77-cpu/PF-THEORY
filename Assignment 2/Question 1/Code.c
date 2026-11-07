/* Program: Cinema Hall Seat Booking Management System
Programmer: Abdul Hayee Kamboh
Roll No: 26K-0026
Section: BSAI-1A */
#include <stdio.h>
int main() 
{
    int rows, cols;
    // 1.INPUT SEATING PLAN DIMENSIONS
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of seats per row: ");
    scanf("%d", &cols);

    // Declare a 2D array for the seating plan using Variable Length Arrays (VLA)
    int seat[rows][cols];

    // ---------- POPULATE INITIAL SEATING MATRIX ----------
    printf("\nEnter the current seating status for each seat (0 for available, 1 for booked):\n");
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            printf("Row %d, Seat %d: ", i, j);
            scanf("%d", &seat[i][j]);
        }
    }
    
    // 2. DISPLAY INITIAL SEATING ARRANGEMENT
    printf("\n--- Initial Seating Arrangement ---\n");
    printf("    ");
    for (int j = 0; j < cols; j++) 
    {
        printf("%d ", j); // Print column numbers starting from 0
    }
    printf("\n");

    for (int i = 0; i < rows; i++) 
    {
        printf("%d: ", i); // Print row number starting from 0
        for (int j = 0; j < cols; j++) 
        {
            if (seat[i][j] == 0) 
            {
                printf("_ "); // '_' represents an available seat
            } 
            else 
            {
                printf("X "); // 'X' represents a booked seat
            }
        }
        printf("\n");
    }
    
    // 3. SEAT AVAILABILITY REPORT
    int total_available = 0;
    printf("\n--- Seat Availability Report ---\n");
    for (int i = 0; i < rows; i++) 
    {
        int row_available = 0;
        for (int j = 0; j < cols; j++) 
        {
            if (seat[i][j] == 0) 
            {
                row_available++;
            }
        }
        total_available += row_available;
        printf("Row %d: %d available seat(s)\n", i, row_available);
    }
    printf("Total available seats in the entire hall: %d\n", total_available);
    
    // 4. GROUP BOOKING & VALIDATION
    int k;
    while (1) 
    {
        printf("\nEnter the number of customers who want to sit together (k): ");
        scanf("%d", &k);
        // Validate that group size is greater than 0 and does not exceed seats in a row
        if (k > 0 && k <= cols) 
        {
            break;
        }
        printf("Invalid group size! Group size must be between 1 and %d.\n", cols);
    }

    // 5. SEAT ALLOCATION RULES & SEARCH ALGORITHM
    
    int mid = rows / 2; // Middle row calculated using integer division
    int found = 0;
    int target_row = -1;
    int target_start_col = -1;

    // Search rows in increasing order of distance from the middle row
    for (int d = 0; d < rows; d++) 
    {
        int rows_to_check[2];
        int count_to_check = 0;

        if (d == 0) 
        {
            // Distance 0 is the middle row itself
            if (mid >= 0 && mid < rows) 
            {
                rows_to_check[0] = mid;
                count_to_check = 1;
            }
        } 
        else 
        {
            // For distance d > 0, check rows above and below the middle row
            int r1 = mid - d; // Row above middle
            int r2 = mid + d; // Row below middle

            // Prioritize the row with the smaller row number first (r1 < r2)
            if (r1 >= 0) 
            {
                rows_to_check[count_to_check++] = r1;
            }
            if (r2 < rows) 
            {
                rows_to_check[count_to_check++] = r2;
            }
        }

        // Check each selected row for k consecutive available seats
        for (int i = 0; i < count_to_check; i++) 
        {
            int r = rows_to_check[i];
            int consecutive_count = 0;
            int start_col = -1;

            // Search from lowest seat number (left to right)
            for (int c = 0; c < cols; c++) 
            {
                if (seat[r][c] == 0) 
                {
                    if (consecutive_count == 0) 
                    {
                        start_col = c; // Mark start of the block
                    }
                    consecutive_count++;

                    // Check if we found k consecutive available seats
                    if (consecutive_count == k) 
                    {
                        found = 1;
                        target_row = r;
                        target_start_col = start_col;
                        break;
                    }
                } 
                else 
                {
                    // Reset count when a booked seat is met
                    consecutive_count = 0;
                    start_col = -1;
                }
            }
            // Stop searching as soon as the first suitable block is found
            if (found) 
            {
                break;
            }
        }
        if (found) 
        {
            break;
        }
    }

    // ==========================================
    // 6. CONFIRM BOOKING & 7. HANDLE UNSUCCESSFUL BOOKINGS
    // ==========================================
    if (found) 
    {
        printf("\n--- Booking Successful! ---\n");
        printf("Allocated Row Number: %d\n", target_row);
        printf("Allocated Seat Numbers: ");
        
        // Mark allocated seats as booked (1)
        for (int j = target_start_col; j < target_start_col + k; j++) 
        {
            printf("%d ", j);
            seat[target_row][j] = 1;
        }
        printf("\n");

        // Display updated seating arrangement
        printf("\n--- Updated Seating Arrangement ---\n");
        printf("    ");
        for (int j = 0; j < cols; j++) 
        {
            printf("%d ", j);
        }
        printf("\n");

        int remaining_available = 0;
        for (int i = 0; i < rows; i++) 
        {
            printf("%d: ", i);
            for (int j = 0; j < cols; j++) 
            {
                if (seat[i][j] == 0) 
                {
                    printf("_ ");
                    remaining_available++;
                } 
                else 
                {
                    printf("X ");
                }
            }
            printf("\n");
        }
        printf("Remaining number of available seats in the hall: %d\n", remaining_available);

    } 
    else 
    {
        // If no suitable block of k consecutive seats is found
        printf("\n--- Booking Unsuccessful ---\n");
        printf("Sorry, no row contains %d consecutive available seats.\n", k);
        printf("The seating plan remains unchanged.\n");
    }

    return 0;
}
