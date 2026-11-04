/*Programmer: Abdul Hayee Kamboh
Program: University Library Management System
Roll No: 26K-0026
Section: BSAI-1A*/
#include <stdio.h>
#include <string.h>

/* Function 1: shows all menu options */
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

/* Function 2: inputs member details (1 = Student, 2 = Faculty) */
void registerMember(char name[], int *studentID, int *memberType)
{
    printf("\nEnter member name: ");
    scanf(" %[^\n]", name);              /* reads name with spaces */

    printf("Enter student ID: ");
    scanf("%d", studentID);

    printf("Membership type (1 = Student, 2 = Faculty): ");
    scanf("%d", memberType);

    /* keep asking until the type is valid */
    while (*memberType != 1 && *memberType != 2)
    {
        printf("Invalid type! Enter 1 for Student or 2 for Faculty: ");
        scanf("%d", memberType);
    }

    printf("Member registered successfully.\n");
}

/* Function 3: displays all books in a table */
void displayBooks(int bookIDs[], char bookTitles[][50], int availableCopies[], int totalBooks)
{
    int i;

    printf("\n%-10s %-30s %s\n", "Book ID", "Title", "Available Copies");
    printf("------------------------------------------------------\n");

    for (i = 0; i < totalBooks; i++)
    {
        printf("%-10d %-30s %d\n", bookIDs[i], bookTitles[i], availableCopies[i]);
    }
}

/* Function 4: borrows a book for the member */
void borrowBook(int bookIDs[], char bookTitles[][50], int availableCopies[],
                int totalBooks, int borrowedBookIDs[], int *borrowedCount, int memberType)
{
    int bookID, days, i, index = -1, allowedDays;

    /* maximum three books at a time */
    if (*borrowedCount >= 3)
    {
        printf("Limit reached! You can borrow only 3 books at a time.\n");
        return;
    }

    printf("Enter book ID: ");
    scanf("%d", &bookID);

    /* search the book in the inventory */
    for (i = 0; i < totalBooks; i++)
    {
        if (bookIDs[i] == bookID)
            index = i;
    }

    if (index == -1)
    {
        printf("Invalid book ID!\n");
        return;
    }

    if (availableCopies[index] == 0)
    {
        printf("Sorry, no copies of \"%s\" are available.\n", bookTitles[index]);
        return;
    }

    printf("Enter number of days you want to keep the book: ");
    scanf("%d", &days);

    /* days must be positive */
    while (days <= 0)
    {
        printf("Days must be positive. Enter again: ");
        scanf("%d", &days);
    }

    if (memberType == 1)
        allowedDays = 14;
    else
        allowedDays = 30;

    /* record the borrowing and reduce stock by one */
    borrowedBookIDs[*borrowedCount] = bookID;
    (*borrowedCount)++;
    availableCopies[index]--;

    printf("You borrowed \"%s\".\n", bookTitles[index]);
    printf("Allowed period is %d days.", allowedDays);
    if (days > allowedDays)
        printf(" Note: you want to keep it longer, so a late fine will apply after %d days.", allowedDays);
    printf("\n");
}

/* Function 5: returns a book, calculates fine, returns fine payable */
float returnBook(int bookIDs[], int availableCopies[], int totalBooks,
                 int borrowedBookIDs[], int *borrowedCount, int memberType, float *totalFine)
{
    int bookID, days, i, pos = -1, index = -1;
    int allowedDays, ratePerDay, extraDays;
    float fine = 0, payable = 0;
    char code[20];

    if (*borrowedCount == 0)
    {
        printf("You have no borrowed books to return.\n");
        return 0;
    }

    printf("Enter book ID to return: ");
    scanf("%d", &bookID);

    /* check that the member has borrowed this book */
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

    printf("Enter actual number of days the book was kept: ");
    scanf("%d", &days);

    /* days must be positive */
    while (days <= 0)
    {
        printf("Days must be positive. Enter again: ");
        scanf("%d", &days);
    }

    /* find the book in the inventory and increase its copies */
    for (i = 0; i < totalBooks; i++)
    {
        if (bookIDs[i] == bookID)
            index = i;
    }
    availableCopies[index]++;

    /* allowed days and fine rate depend on the member type */
    if (memberType == 1)
    {
        allowedDays = 14;
        ratePerDay = 20;
    }
    else
    {
        allowedDays = 30;
        ratePerDay = 10;
    }

    if (days > allowedDays)
    {
        extraDays = days - allowedDays;
        fine = extraDays * ratePerDay;
        printf("Book returned late by %d day(s). Fine = Rs. %.2f\n", extraDays, fine);

        printf("Enter membership code for fine waiver: ");
        scanf("%s", code);

        if (strcmp(code, "LIB2026") == 0)
        {
            payable = fine * 0.5;        /* 50% waiver */
            printf("Correct code! 50%% waiver applied. Fine payable = Rs. %.2f\n", payable);
        }
        else
        {
            payable = fine;              /* no waiver */
            printf("Wrong code! No waiver. Fine payable = Rs. %.2f\n", payable);
        }

        *totalFine = *totalFine + fine;  /* fine before waiver */
    }
    else
    {
        printf("Book returned on time. No fine.\n");
    }

    /* remove the book from the borrowed list (shift remaining books left) */
    for (i = pos; i < *borrowedCount - 1; i++)
    {
        borrowedBookIDs[i] = borrowedBookIDs[i + 1];
    }
    (*borrowedCount)--;

    return payable;
}

/* Function 6: displays member information and record */
void displayMemberRecord(char name[], int studentID, int memberType,
                         int borrowedBookIDs[], int borrowedCount,
                         float totalFine, float fineAfterWaiver)
{
    int i;

    printf("\n===== Member Record =====\n");
    printf("Name            : %s\n", name);
    printf("Student ID      : %d\n", studentID);

    if (memberType == 1)
        printf("Membership type : Student\n");
    else
        printf("Membership type : Faculty\n");

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

    printf("Total fine (before waiver) : Rs. %.2f\n", totalFine);
    printf("Final fine payable         : Rs. %.2f\n", fineAfterWaiver);
}

int main()
{
    /* book inventory (4 books, copies 5 3 0 4) */
    int bookIDs[4] = {101, 102, 103, 104};
    char bookTitles[4][50] = {"C Programming", "Data Structures",
                              "Database Systems", "Operating Systems"};
    int availableCopies[4] = {5, 3, 0, 4};
    int totalBooks = 4;

    /* member record */
    char name[50] = "";
    int studentID = 0;
    int memberType = 0;
    int borrowedBookIDs[3];
    int borrowedCount = 0;
    float totalFine = 0;
    float fineAfterWaiver = 0;
    int registered = 0;          /* 0 = no member registered yet */

    int choice;

    do
    {
        displayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (registered == 1 && borrowedCount > 0)
                {
                    printf("Current member still has borrowed books. Return them first.\n");
                }
                else
                {
                    registerMember(name, &studentID, &memberType);
                    registered = 1;
                    borrowedCount = 0;       /* start a fresh record */
                    totalFine = 0;
                    fineAfterWaiver = 0;
                }
                break;

            case 2:
                displayBooks(bookIDs, bookTitles, availableCopies, totalBooks);
                break;

            case 3:
                if (registered == 0)
                    printf("Please register a member first (option 1).\n");
                else
                    borrowBook(bookIDs, bookTitles, availableCopies, totalBooks,
                               borrowedBookIDs, &borrowedCount, memberType);
                break;

            case 4:
                if (registered == 0)
                    printf("Please register a member first (option 1).\n");
                else
                    fineAfterWaiver = fineAfterWaiver +
                        returnBook(bookIDs, availableCopies, totalBooks,
                                   borrowedBookIDs, &borrowedCount, memberType, &totalFine);
                break;

            case 5:
                if (registered == 0)
                    printf("Please register a member first (option 1).\n");
                else
                    displayMemberRecord(name, studentID, memberType, borrowedBookIDs,
                                        borrowedCount, totalFine, fineAfterWaiver);
                break;

            case 6:
                printf("Exiting program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please enter a number from 1 to 6.\n");
        }
    } while (choice != 6);

    return 0;
}
