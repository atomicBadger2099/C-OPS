#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function declarations
int prompt_continue();
void process_input();

int main() {
    while (prompt_continue()) {
        process_input();
    }

    printf("Program terminated.\n");
    return 0;
}

// Function to prompt the user whether to continue
int prompt_continue() {
    char response[10];

    printf("Would you like to enter a line of text? (y/n): ");
    fgets(response, sizeof(response), stdin);

    // Check if first character is 'y' or 'Y'
    return response[0] == 'y' || response[0] == 'Y';
}

// Function to process the input and categorize characters
void process_input() {
    char input[51]; // 50 characters + 1 for null terminator
    int letters = 0, digits = 0, whitespace = 0, punctuation = 0, others = 0;

    printf("Enter a line of up to 50 characters:\n");
    fgets(input, sizeof(input), stdin);

    // Remove trailing newline if present
    input[strcspn(input, "\n")] = '\0';

    for (int i = 0; input[i] != '\0'; ++i) {
        unsigned char ch = (unsigned char)input[i];
        if (isalpha(ch)) {
            ++letters;
        } else if (isdigit(ch)) {
            ++digits;
        } else if (isspace(ch)) {
            ++whitespace;
        } else if (ispunct(ch)) {
            ++punctuation;
        } else {
            ++others;
        }
    }

    printf("Character breakdown:\n");
    printf("Letters:     %d\n", letters);
    printf("Digits:      %d\n", digits);
    printf("Whitespace:  %d\n", whitespace);
    printf("Punctuation: %d\n", punctuation);
    printf("Other:       %d\n\n", others);
}

