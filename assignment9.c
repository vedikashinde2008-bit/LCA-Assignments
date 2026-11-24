#include <stdio.h>

struct Robot
{
    float depth;
    float pressure;
    float temperature;
    float battery;
    char defect[50];
};

int main()
{
    struct Robot r;
    FILE *fp, *rp;
    int unsafeCount = 0, total = 0, unsafe;
    int depthFlag, pressureFlag, tempFlag, batteryFlag, defectFlag;


    printf("Enter robot depth (m): ");
    scanf("%f", &r.depth);

    printf("Enter water pressure (MPa): ");
    scanf("%f", &r.pressure);

    printf("Enter temperature (C): ");
    scanf("%f", &r.temperature);

    printf("Enter battery percentage: ");
    scanf("%f", &r.battery);

    printf("Enter defect type (None if no defect): ");
    scanf("%49s", r.defect);

    
    fp = fopen("robot_records.txt", "a");

    if (fp == NULL)
    {
        printf("Error opening record file.\n");
        return 1;
    }

    fprintf(fp, "%.2f %.2f %.2f %.2f %s\n",
            r.depth, r.pressure, r.temperature,
            r.battery, r.defect);

    fclose(fp);

    
    fp = fopen("robot_records.txt", "r");

    if (fp == NULL)
    {
        printf("Error reading record file.\n");
        return 1;
    }

    
    rp = fopen("underwater_report.txt", "w");

    if (rp == NULL)
    {
        printf("Error creating report file.\n");
        fclose(fp);
        return 1;
    }

    fprintf(rp, "UNDERWATER ROBOT INSPECTION REPORT\n");
    fprintf(rp, "==================================\n");

    while (fscanf(fp, "%f %f %f %f %49s",
                  &r.depth, &r.pressure,
                  &r.temperature, &r.battery,
                  r.defect) == 5)
    {
        total++;
        unsafe = 0;

        depthFlag = (r.depth > 300);
        pressureFlag = (r.pressure >= 30);
        tempFlag = (r.temperature > 35);
        batteryFlag = (r.battery < 20);
        defectFlag = (strcmp(r.defect, "None") != 0);

        fprintf(rp, "\nRecord %d\n", total);
        fprintf(rp, "Depth: %.2f m\n", r.depth);
        fprintf(rp, "Pressure: %.2f MPa\n", r.pressure);
        fprintf(rp, "Temperature: %.2f C\n", r.temperature);
        fprintf(rp, "Battery: %.2f%%\n", r.battery);
        fprintf(rp, "Defect: %s\n", r.defect);

        

        if (depthFlag)
        {
            fprintf(rp, "Unsafe: Depth exceeds 300 m.\n");
            unsafe = 1;
        }

        if (pressureFlag)
        {
            fprintf(rp, "Unsafe: Pressure is 30 MPa or more.\n");
            unsafe = 1;
        }

        if (tempFlag)
        {
            fprintf(rp, "Unsafe: Temperature exceeds 35 C.\n");
            unsafe = 1;
        }

        if (batteryFlag)
        {
            fprintf(rp, "Unsafe: Battery is below 20%%.\n");
            unsafe = 1;
        }

        if (defectFlag)
        {
            fprintf(rp, "Unsafe: Structural defect detected.\n");
            unsafe = 1;
        }

        

        if (unsafe == 1)
        {
            fprintf(rp, "Status: UNSAFE\n");
            unsafeCount++;
        }
        else
        {
            fprintf(rp, "Status: SAFE\n");
        }
    }

   

    fprintf(rp, "\n===== SUMMARY =====\n");
    fprintf(rp, "Total records: %d\n", total);
    fprintf(rp, "Unsafe records: %d\n", unsafeCount);
    fprintf(rp, "Safe records: %d\n", total - unsafeCount);

    fclose(fp);
    fclose(rp);

    printf("\nInspection report generated successfully!");
    printf("\nReport saved in underwater_report.txt\n");

    return 0;
}