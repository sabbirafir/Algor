#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if a string is a palindrome
bool isPalindrome(const char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    FILE *inputFile, *outputFile, *recordsFile;
    inputFile = fopen("input.txt", "r");
    outputFile = fopen("output.txt", "w");
    recordsFile = fopen("records.txt", "w");

    if (inputFile == NULL || outputFile == NULL || recordsFile == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    int totalPairs = 0;
    int evenParityCount = 0;
    int oddParityCount = 0;
    int noParityCount = 0;
    int palindromeCount = 0;
    int nonPalindromeCount = 0;

    while (!feof(inputFile)) {
        float number;
        char string[100];

        if (fscanf(inputFile, "%f %s", &number, string) == 2) {
            totalPairs++;

            // Check for parity
            if (number == (int)number) {
                if ((int)number % 2 == 0) {
                    fprintf(outputFile, "Even Parity: ");
                    evenParityCount++;
                } else {
                    fprintf(outputFile, "Odd Parity: ");
                    oddParityCount++;
                }
            } else {
                fprintf(outputFile, "No Parity: ");
                noParityCount++;
            }

            // Check for palindrome
            if (isPalindrome(string)) {
                fprintf(outputFile, "Palindrome\n");
                palindromeCount++;
            } else {
                fprintf(outputFile, "Non-Palindrome\n");
                nonPalindromeCount++;
            }
        }
    }

    // Calculate and write percentages to records.txt
    fprintf(recordsFile, "Percentage of Even Parity: %.2f%%\n", (float)evenParityCount / totalPairs * 100);
    fprintf(recordsFile, "Percentage of Odd Parity: %.2f%%\n", (float)oddParityCount / totalPairs * 100);
    fprintf(recordsFile, "Percentage of No Parity: %.2f%%\n", (float)noParityCount / totalPairs * 100);
    fprintf(recordsFile, "Percentage of Palindromes: %.2f%%\n", (float)palindromeCount / totalPairs * 100);
    fprintf(recordsFile, "Percentage of Non-Palindromes: %.2f%%\n", (float)nonPalindromeCount / totalPairs * 100);

    fclose(inputFile);
    fclose(outputFile);
    fclose(recordsFile);

    return 0;
}
