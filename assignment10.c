#include <stdio.h>

int main()
{
    int year, month, day;
    int days, startDay;
    int i;

    char *months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    printf("Enter year: ");
    scanf("%d", &year);

    // Calculate the starting day of the year
    int y = year - 1;
    startDay = (y * 365 + y / 4 - y / 100 + y / 400 + 1) % 7;

    for (month = 0; month < 12; month++)
    {
        printf("\n\n       %s %d\n", months[month], year);
        printf(" Sun Mon Tue Wed Thu Fri Sat\n");

        // Calculate number of days in each month
        if (month == 1)
        {
            if ((year % 400 == 0) ||
                (year % 4 == 0 && year % 100 != 0))
                days = 29;
            else
                days = 28;
        }
        else if (month == 3 || month == 5 ||
                 month == 8 || month == 10)
        {
            days = 30;
        }
        else
        {
            days = 31;
        }

        // Print spaces before the first day
        for (i = 0; i < startDay; i++)
            printf("    ");

        // Print dates
        for (day = 1; day <= days; day++)
        {
            printf("%4d", day);

            if ((startDay + day) % 7 == 0)
                printf("\n");
        }

        startDay = (startDay + days) % 7;
    }

    printf("\n");

    return 0;
}