/*Programmer: Abdul Hayee Kamboh
Program: Amicable Pairs
Roll No: 26K-0026
Section: BSAI-1A*/
#include <stdio.h>

// Function to calculate and return the sum of the proper divisors of a number
int sumOfProperDivisors(int num) {
    int sum = 0;
    // Proper divisors are all divisors except the number itself, 
    // so we only check up to num / 2
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int n;
    int pair_count = 0;

    // Input the upper limit n
    printf("Enter a positive integer n: ");
    scanf("%d", &n);

    printf("\n--- Amicable Pairs (up to %d) ---\n", n);

    // Loop through numbers from 1 up to n
    for (int a = 1; a <= n; a++) {
        int b = sumOfProperDivisors(a);

        // Conditions to satisfy:
        // 1. b must be greater than a to ensure we display each pair only once (smaller number first).
        // 2. b must also be less than or equal to n (both numbers within the limit).
        // 3. a and b must be different (automatically true if b > a, which also excludes perfect numbers where a == b).
        if (b > a && b <= n) {
            // Check if the sum of proper divisors of b equals a
            if (sumOfProperDivisors(b) == a) {
                printf("(%d, %d)\n", a, b);
                pair_count++;
            }
        }
    }

    // Display the total number of pairs found or a suitable message if none
    if (pair_count > 0) {
        printf("\nTotal amicable pairs found: %d\n", pair_count);
    } else {
        printf("\nNo amicable pairs found less than or equal to %d.\n", n);
    }

    return 0;
}
