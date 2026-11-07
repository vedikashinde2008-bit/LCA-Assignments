#include <stdio.h>

unsigned long long computeFactorial(int n) {
    if (n < 0) {
        return 0;
    }
    unsigned long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int num = 5;
    unsigned long long result = computeFactorial(num);
    
    if (num >= 0) {
        printf("Factorial of %d is: %llu\n", num, result);
    }
    
    return 0;
}