// Write a c program to printf a 9-digit number backwards and calculate the sum of all its digits

#include<stdio.h>

int main(){
    long n;

    printf("Enter a 9-digit number: ");
    if (scanf("%ld", &n) != 1 || n < 100000000L || n > 999999999L) {
        printf("Invalid input: please enter exactly 9 digits.\n");
        return 1;
    }

    int sum = 0;
    printf("Reversed: ");
    while (n > 0) {
        int digit = n % 10;   // last digit
        printf("%d", digit);  // print it immediately
        sum += digit;
        n /= 10;              // remove the last digit
    }

    printf("\nSum of digits: %d\n", sum);
    return 0;
}
// The L suffix just marks the constant as a long, so it matches the type of n