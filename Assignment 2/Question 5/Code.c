/*Programmer: Abdul Hayee Kamboh
Program: University Library Management System
Roll No: 26K-0026
Section: BSAI-1A*/
#include <stdio.h>
#include <string.h>

// ==========================================
// FUNCTION 1: DISPLAY MENU
// Prints the main interactive menu options for the library user.
// ==========================================
void displayMenu()
{
    printf("\n===== University Library Menu =====\n");
    printf("1. Register Member\n");
    printf("2. Display Available Books\n");
    printf("3. Borrow a Book\n");
    printf("4. Return a Book\n");
    printf("5. Display Member Record\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

// ==========================================
// FUNCTION 2: REGISTER MEMBER
// Takes inputs for member name, student/faculty ID, and membership type.
// Validates that the membership type is strictly 1 or 2.
// ==========================================
void registerMember(char name[], int *studentID, int *memberType)
{
    // Prompt and read member's full name (including spaces)
    printf("\nEnter member name: ");
    scanf(" %[^\n]", name);             /* reads name with spaces */

    // Prompt and read identification number
    printf("Enter student ID: ");
    scanf("%d", studentID);

    // Prompt and read membership category
    printf("Membership type (1 = Student, 2 = Faculty): ");
    scanf("%d", memberType);

    /* Keep looping until a valid membership type (1 or 2) is entered */
    while (*memberType != 1 && *memberType != 2)
    {
        printf("Invalid type! Enter 1 for Student or 2 for Faculty: ");
        scanf("%d", memberType);
    }

    printf("Member registered successfully.\n");
}

// ==========================================
// FUNCTION 3: DISPLAY BOOKS
// Prints the complete inventory of books, their IDs, titles, 
// and currently available copies in a formatted tabular structure.
// ==========================================
void displayBooks(int bookIDs[], char bookTitles[][50], int availableCopies[], int totalBooks)
{
    int i;

    // Print table header with alignment widths
    printf("\n%-10s %-30s %s\n", "Book ID", "Title", "Available Copies");
    printf("------------------------------------------------------\n");

    // Loop through all inventory items and display their details
    for (i = 0; i < totalBooks; i++)
    {
        printf("%-10d %-30s %d\n", bookIDs[i], bookTitles[i], availableCopies[i]);
    }
}

// ==========================================
// FUNCTION 4: BORROW A BOOK
// Handles book borrowing logic, checks borrowing limits (max 3 books),
// verifies stock availability, calculates allowed loan duration, and updates inventory.
// ==========================================
void borrowBook(int bookIDs[], char bookTitles[][50], int availableCopies[],
                int totalBooks, int borrowedBookIDs[], int *borrowedCount, int memberType)
{
    int bookID, days, i, index = -1, allowedDays;

    /* Check if the user has already reached the maximum limit of 3 borrowed books */
    if (*borrowedCount >= 3)
    {
        printf("Limit reached! You can borrow only 3 books at a time.\n");
        return;
    }

    // Prompt for the target book ID
    printf("Enter book ID: ");
    scanf("%d", &bookID);

    /* Search for the entered book ID within the inventory array */
    for (i = 0; i < totalBooks; i++)
    {
        if (bookIDs[i] == bookID)
            index = i;
    }

    // Validate if the book ID exists
    if (index == -1)
    {
        printf("Invalid book ID!\n");
        return;
    }

    // Validate if physical copies are available in stock
    if (availableCopies[index] == 0)
    {
        printf("Sorry, no copies of \"%s\" are available.\n", bookTitles[index]);
        return;
    }

    // Prompt for desired loan duration in days
    printf("Enter number of days you want to keep the book: ");
    scanf("%d", &days);

    /* Ensure that the number of days entered is positive */
    while (days <= 0)
    {
        printf("Days must be positive. Enter again: ");
        scanf("%d", &days);
    }

    // Assign allowed loan period based on membership type (Student = 14 days, Faculty = 30 days)
    if (memberType == 1)
        allowedDays = 14;
    else
        allowedDays = 30;

    /* Record the borrowed book ID in user profile, increment count, and reduce stock */
    borrowedBookIDs[*borrowedCount] = bookID;
    (*borrowedCount)++;
    availableCopies[index]--;

    // Output success message and late fine warning if applicable
    printf("You borrowed \"%s\".\n", bookTitles[index]);
    printf("Allowed period is %d days.", allowedDays);
    if (days > allowedDays)
        printf(" Note: you want to keep it longer, so a late fine will apply after %d days.", allowedDays);
    printf("\n");
}

// ==========================================
// FUNCTION 5: RETURN A BOOK
// Handles book returns, restores stock, calculates overdue late fines 
// according to membership rates, handles membership code waiver, and updates records.
// ==========================================
float returnBook(int bookIDs[], int availableCopies[], int totalBooks,
                 int borrowedBookIDs[], int *borrowedCount, int memberType, float *totalFine)
{
    int bookID, days, i, pos = -1, index = -1;
    int allowedDays, ratePerDay, extraDays;
    float fine = 0, payable = 0;
    char code[20];

    // Check if user currently has any books checked out
    if (*borrowedCount == 0)
    {
        printf("You have no borrowed books to return.\n");
        return 0;
    }

    // Prompt for book ID to return
    printf("Enter book ID to return: ");
    scanf("%d", &bookID);

    /* Verify that the member actually borrowed this specific book */
    for (i = 0; i < *borrowedCount; i++)
    {
        if (borrowedBookIDs[i] == bookID)
            pos = i;
    }

    if (pos == -1)
    {
        printf("You have not borrowed this book!\n");
        return 0;
    }

    // Prompt for actual days the book was kept
    printf("Enter actual number of days the book was kept: ");
    scanf("%d", &days);

    /* Validate that days kept is greater than zero */
    while (days <= 0)
    {
        printf("Days must be positive. Enter again: ");
        scanf("%d", &days);
    }

    /* Locate the book in the inventory array and restore its copy count */
    for (i = 0; i < totalBooks; i++)
    {
        if (bookIDs[i] == bookID)
            index = i;
    }
    availableCopies[index]++;

    /* Determine allowed days and daily fine rate based on membership type */
    if (memberType == 1)
    {
        allowedDays = 14;
        ratePerDay = 20;     // Student fine rate: Rs. 20 per extra day
    }
    else
    {
        allowedDays = 30;
        ratePerDay = 10;     // Faculty fine rate: Rs. 10 per extra day
    }

    // Check if the book was returned late
    if (days > allowedDays)
    {
        extraDays = days - allowedDays;
        fine = extraDays * ratePerDay;
        printf("Book returned late by %d day(s). Fine = Rs. %.2f\n", extraDays, fine);

        // Prompt for promotional waiver code
        printf("Enter membership code for fine waiver: ");
        scanf("%s", code);

        // Check if correct waiver code is entered
        if (strcmp(code, "LIB2026") == 0)
        {
            payable = fine * 0.5;        /* Apply 50% waiver discount */
            printf("Correct code! 50%% waiver applied. Fine payable = Rs. %.2f\n", payable);
        }
        else
        {
            payable = fine;              /* No waiver applied */
            printf("Wrong code! No waiver. Fine payable = Rs. %.2f\n", payable);
        }

        *totalFine = *totalFine + fine;  /* Accumulate original fine before waiver */
    }
    else
    {
        printf("Book returned on time. No fine.\n");
    }

    /* Remove the returned book ID from the borrowed list by shifting elements left */
    for (i = pos; i < *borrowedCount - 1; i++)
    {
        borrowedBookIDs[i] = borrowedBookIDs[i + 1];
    }
    (*borrowedCount)--;

    return payable;
}

// ==========================================
// FUNCTION 6: DISPLAY MEMBER RECORD
// Outputs comprehensive details of the registered member, 
// including active borrowed book IDs and accumulated fine summaries.
// ==========================================
void displayMemberRecord(char name[], int studentID, int memberType,
                         int borrowedBookIDs[], int borrowedCount,
                         float totalFine, float fineAfterWaiver)
{
    int i;

    // Print header and member personal details
    printf("\n===== Member Record =====\n");
    printf("Name            : %s\n", name);
    printf("Student ID      : %d\n", studentID);

    // Display membership category string representation
    if (memberType == 1)
        printf("Membership type : Student\n");
    else
        printf("Membership type : Faculty\n");

    // Display currently borrowed books list or None
    printf("Borrowed books  : ");
    if (borrowedCount == 0)
    {
        printf("None");
    }
    else
    {
        for (i = 0; i < borrowedCount; i++)
            printf("%d ", borrowedBookIDs[i]);
    }
    printf("\n");

    // Print financial fine records
    printf("Total fine (before waiver) : Rs. %.2f\n", totalFine);
    printf("Final fine payable         : Rs. %.2f\n", fineAfterWaiver);
}

// ==========================================
// MAIN FUNCTION
// Controls program execution loop, initializes inventory and member states, 
// and routes user menu selections to appropriate functions.
// ==========================================
int main()
{
    /* Initialize book inventory database (4 books with pre-set stock copies) */
    int bookIDs[4] = {101, 102, 103, 104};
    char bookTitles[4][50] = {"C Programming", "Data Structures",
                              "Database Systems", "Operating Systems"};
    int availableCopies[4] = {5, 3, 0, 4};
    int totalBooks = 4;

    /* Initialize member profile tracking variables */
    char name[50] = "";
    int studentID = 0;
    int memberType = 0;
    int borrowedBookIDs[3];
    int borrowedCount = 0;
    float totalFine = 0;
    float fineAfterWaiver = 0;
    int registered = 0;          /* Status flag: 0 = unregistered, 1 = registered */

    int choice;

    // Main interactive control loop using do-while
    do
    {
        displayMenu();
        scanf("%d", &choice);

        // Switch-case block to route user choice
        switch (choice)
        {
            case 1: // Register Member option
                if (registered == 1 && borrowedCount > 0)
                {
                    printf("Current member still has borrowed books. Return them first.\n");
                }
                else
                {
                    registerMember(name, &studentID, &memberType);
                    registered = 1;
                    borrowedCount = 0;       /* Reset profile state for new member */
                    totalFine = 0;
                    fineAfterWaiver = 0;
                }
                break;

            case 2: // Display Available Books option
                displayBooks(bookIDs, bookTitles, availableCopies, totalBooks);
                break;

            case 3: // Borrow a Book option
                if (registered == 0)
                    printf("Please register a member first (option 1).\n");
                else
                    borrowBook(bookIDs, bookTitles, availableCopies, totalBooks,
                               borrowedBookIDs, &borrowedCount, memberType);
                break;

            case 4: // Return a Book option
                if (registered == 0)
                    printf("Please register a member first (option 1).\n");
                else
                    fineAfterWaiver = fineAfterWaiver +
                        returnBook(bookIDs, availableCopies, totalBooks,
                                   borrowedBookIDs, &borrowedCount, memberType, &totalFine);
                break;

            case 5: // Display Member Record option
                if (registered == 0)
                    printf("Please register a member first (option 1).\n");
                else
                    displayMemberRecord(name, studentID, memberType, borrowedBookIDs,
                                        borrowedCount, totalFine, fineAfterWaiver);
                break;

            case 6: // Exit program option
                printf("Exiting program. Goodbye!\n");
                break;

            default: // Handle invalid inputs
                printf("Invalid choice! Please enter a number from 1 to 6.\n");
        }
    } while (choice != 6);

    return 0;
}
