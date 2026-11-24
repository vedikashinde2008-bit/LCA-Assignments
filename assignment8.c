#include <stdio.h>

int main()
{
    int motor1, motor2, temp;
    int *ptr1, *ptr2;

    printf("Enter speed of Motor 1: ");
    scanf("%d", &motor1);

    printf("Enter speed of Motor 2: ");
    scanf("%d", &motor2);

    ptr1 = &motor1;
    ptr2 = &motor2;

    printf("\nBefore swapping:\n");
    printf("Motor 1 speed = %d\n", motor1);
    printf("Motor 2 speed = %d\n", motor2);

    printf("\nMemory addresses:\n");
    printf("Motor 1 address = %p\n", (void *)ptr1);
    printf("Motor 2 address = %p\n", (void *)ptr2);

    // Swapping speeds using pointers
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;

    printf("\nAfter swapping:\n");
    printf("Motor 1 speed = %d\n", motor1);
    printf("Motor 2 speed = %d\n", motor2);

    printf("\nVerification of memory addresses:\n");
    printf("Motor 1 address = %p\n", (void *)ptr1);
    printf("Motor 2 address = %p\n", (void *)ptr2);

    return 0;
}