#include <stdio.h>


unsigned long long factorial(int n) {
    
    if (n == 0 || n == 1) {
        return 1;
    }
    
    
    return n * factorial(n - 1);
}

int main() {
    int n;

    printf("=========================================\n");
    printf("     RECURSIVE FACTORIAL CALCULATOR      \n");
    printf("=========================================\n");
    printf("Enter a non-negative integer (0 to 20): ");
    
    
    if (scanf("%d", &n) != 1) {
        printf("Invalid input! Please enter a valid integer.\n");
        return 1;
    }

    
    if (n < 0) {
        printf("Error: Factorial is not defined for negative numbers.\n");
    } 
    
    else if (n > 20) {
        printf("Error: Number is too large! Enter a value between 0 and 20 to avoid overflow.\n");
    } 
    else {
        unsigned long long result = factorial(n);
        printf("\n-----------------------------------------\n");
        printf("Factorial of %d (computed recursively) is: %llu\n", n, result);
        printf("-----------------------------------------\n");
    }

    return 0;
}