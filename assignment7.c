#include <stdio.h>
#include <string.h>

#define MAX_SENSORS 100

// Structure definition for a Sensor
struct Sensor {
    int sensorId;
    char sensorType[40];
    float measuredValue;
    float minLimit;
    float maxLimit;
};

// Helper function to remove trailing newline from fgets input
void remove_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main() {
    struct Sensor sensors[MAX_SENSORS];
    int n, i;
    int normalCount = 0, warningCount = 0, anomalyCount = 0;

    printf("=========================================================\n");
    printf("        INDUSTRIAL SENSOR MONITORING & CLASSIFICATION    \n");
    printf("=========================================================\n");
    printf("Enter the number of sensors to record (max %d): ", MAX_SENSORS);
    
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_SENSORS) {
        printf("Error: Invalid number of sensors entered.\n");
        return 1;
    }

    // Input loop for capturing sensor data
    for (i = 0; i < n; i++) {
        printf("\n--- Enter Details for Sensor %d ---\n", i + 1);
        
        printf("Sensor ID (integer): ");
        scanf("%d", &sensors[i].sensorId);
        
        while (getchar() != '\n'); // Clear input buffer after reading integer

        printf("Sensor Type (e.g., Temperature, Pressure): ");
        fgets(sensors[i].sensorType, sizeof(sensors[i].sensorType), stdin);
        remove_newline(sensors[i].sensorType);

        printf("Measured Value: ");
        scanf("%f", &sensors[i].measuredValue);

        printf("Minimum Limit: ");
        scanf("%f", &sensors[i].minLimit);

        printf("Maximum Limit: ");
        scanf("%f", &sensors[i].maxLimit);
    }

    // Displaying the classified report in a clean tabular format
    printf("\n===================================================================================\n");
    printf("                           SENSOR CLASSIFICATION REPORT                            \n");
    printf("===================================================================================\n");
    printf("%-8s %-15s %-10s %-8s %-8s %-25s\n", "ID", "Type", "Value", "Min", "Max", "Status Classification");
    printf("-----------------------------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        char status[35];
        float val = sensors[i].measuredValue;
        float minL = sensors[i].minLimit;
        float maxL = sensors[i].maxLimit;

        // 10% tolerance bounds outside the normal limits
        float lowWarningThreshold = minL - (0.10 * minL);
        float highWarningThreshold = maxL + (0.10 * maxL);

        // Classification Logic
        if (val >= minL && val <= maxL) {
            strcpy(status, "1) Normal");
            normalCount++;
        } 
        else if ((val >= lowWarningThreshold && val < minL) || (val > maxL && val <= highWarningThreshold)) {
            strcpy(status, "2) Warning");
            warningCount++;
        } 
        else {
            strcpy(status, "3) Anomaly");
            anomalyCount++;
        }

        // Printing formatted table row
        printf("%-8d %-15s %-10.2f %-8.2f %-8.2f %-25s\n",
               sensors[i].sensorId,
               sensors[i].sensorType,
               val,
               minL,
               maxL,
               status);
    }
    printf("===================================================================================\n");

    // Summary Section
    int totalAbnormal = warningCount + anomalyCount;
    printf("\n----------------------------------------------------\n");
    printf("                     SUMMARY REPORT                 \n");
    printf("----------------------------------------------------\n");
    printf("Total Sensors Monitored : %d\n", n);
    printf("Normal Readings         : %d\n", normalCount);
    printf("Warning Readings        : %d\n", warningCount);
    printf("Anomaly Readings        : %d\n", anomalyCount);
    printf("----------------------------------------------------\n");
    printf("Total Abnormal Sensors  : %d (Warning + Anomaly)\n", totalAbnormal);
    printf("================================================----\n");

    return 0;
}