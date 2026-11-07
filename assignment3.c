#include <stdio.h>

int main() {
    int choice;
    double num1, num2, result;

    do {
        // Displaying the menu
        printf("\n====================================\n");
        printf("      BASIC ARITHMETIC CALCULATOR     \n");
        printf("====================================\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Exit\n");
        printf("------------------------------------\n");
        printf("Enter your choice (1-5): ");
        
        // Input validation for menu choice
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a valid number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        // Exit condition
        if (choice == 5) {
            printf("Exiting program. Thank you!\n");
            break;
        }

        // Read operands for valid arithmetic choices
        if (choice >= 1 && choice <= 4) {
            printf("Enter two numbers: ");
            if (scanf("%lf %lf", &num1, &num2) != 2) {
                printf("Invalid number input!\n");
                while (getchar() != '\n');
                continue;
            }
        }

        // Performing operation based on user choice
        switch (choice) {
            case 1:
                result = num1 + num2;
                printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 2:
                result = num1 - num2;
                printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 3:
                result = num1 * num2;
                printf("Result: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 4:
                if (num2 == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                } else {
                    result = num1 / num2;
                    printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
                }
                break;
            default:
                printf("Invalid choice! Please select an option between 1 and 5.\n");
        }

    } while (choice != 5);

    return 0;
}