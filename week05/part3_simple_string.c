// part3_simple_string.c
//
// This program was written by Sofia De Bellis (z5418801) on March 2024
// and lightly edited by Caitlyn Wong (z5360361)
//
// This program demonstrates how to work with strings in C


#include <stdio.h>

#define MAX_SIZE 1024

int main(void) {
    // Declare and initialise a string
    char my_string[] = "hello world!";
    
    // Traverse the string and print each character
    printf("Traverse the string and print each character using a while loop:\n");
    int i = 0;
    while (my_string[i] != '\0') {
        printf("%c", my_string[i]);
        i++;
    }
    printf("\n\n");

    // Another way to traverse the string and print each character
    printf("Traverse the string and print each character using a for loop:\n");
    for (int i = 0; my_string[i] != '\0'; i++) {
        printf("%c", my_string[i]);
    }
    printf("\n\n");

    // How to print a string in its entirety
    printf("Print a string in its entirety using printf():\n");
    printf("My string: %s\n\n", my_string);


    // Declare a string
    char another_string[MAX_SIZE];
    
    // Read a string from the user, note we do NOT use scanf for strings
    printf("Enter a string: ");
    fgets(another_string, MAX_SIZE, stdin);
    
    // Print the string using fputs
    printf("Print the string using fputs:\n");
    fputs(another_string, stdout);
    printf("\n");

    // Print the string one character at a time
    printf("Print the string one character at a time:\n");
    for (int i = 0; another_string[i] != '\0'; i++) {
        if (another_string[i] == '\n') {
            printf("\\n");
        } else {
            printf("%c,", another_string[i]);
        }
    }
    printf("\n");

    return 0;
}