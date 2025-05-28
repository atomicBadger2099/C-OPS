// CELSIUS CONVERSION PROGRAM


#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Convert Fahrenheit to Celsius
float fahrenheitToCelsius(float f) {
    return (f - 32) * 5 / 9;
}

// Convert Celsius to Fahrenheit
float celsiusToFahrenheit(float c) {
    return (c * 9 / 5) + 32;
}

// Read a valid float input from the user
int getFloatInput(const char *prompt, float *value) {
    char buffer[100];
    char *endptr;

    printf("%s", prompt);
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        // Remove trailing newline
        buffer[strcspn(buffer, "\n")] = 0;

        *value = strtof(buffer, &endptr);
        if (endptr == buffer || *endptr != '\0') {
            printf("Invalid numeric input.\n");
            return 0; // Failure
        }
        return 1; // Success
    }
    return 0;
}

// Function to handle temperature conversion
void temperatureConversion() {
    float inputTemp, resultTemp;
    char direction[10];
    char choice[10];

    do {
        printf("Convert to (C)elsius or (F)ahrenheit? Enter C or F: ");
        if (!fgets(direction, sizeof(direction), stdin)) break;
        direction[0] = tolower(direction[0]);

        if (direction[0] == 'c') {
            if (getFloatInput("Enter temperature in Fahrenheit: ", &inputTemp)) {
                resultTemp = fahrenheitToCelsius(inputTemp);
                printf("Temperature in Celsius: %.2f°C\n", resultTemp);
            }
        } else if (direction[0] == 'f') {
            if (getFloatInput("Enter temperature in Celsius: ", &inputTemp)) {
                resultTemp = celsiusToFahrenheit(inputTemp);
                printf("Temperature in Fahrenheit: %.2f°F\n", resultTemp);
            }
        } else {
            printf("Invalid choice. Please enter C or F.\n");
            continue;
        }

        printf("Do you want to convert another temperature? (y/n): ");
        if (!fgets(choice, sizeof(choice), stdin)) break;
        choice[0] = tolower(choice[0]);

    } while (choice[0] == 'y');

    printf("Program ended.\n");
}

int main() {
    temperatureConversion();
    return 0;
}

