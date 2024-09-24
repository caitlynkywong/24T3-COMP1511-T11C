// example_program.c
// 
// Written by Sofia, De Bellis (z5418801) on June 2024
// and Caitlyn Wong (z5360361)
//
// This program demonstrates a simple example of reading three characters 
// from the user input using the terminal buffer. It illustrates how the 
// terminal buffer can be used to capture and process user input. The program 
// prompts the user to enter three characters one at a time, and then it scans
// them in one at a time and prints out each character immediately 
// after it is entered.

#include <stdio.h>

int main(void) {
    printf("Enter 3 chars: ");

    int i = 0;
    while (i < 3) {
        char letter;
        scanf(" %c", &letter);
        printf("The #%d letter inputted was: %c\n", i + 1, letter);
        i++;
    }

    // char a;
    // scanf(" %c", &a);
    // printf("The first letter inputted was: %c\n", a);

    // char b;
    // scanf(" %c", &b);
    // printf("The second letter inputted was: %c\n", b);

    // char c;
    // scanf(" %c", &c);
    // printf("The third letter inputted was: %c\n", c);

    return 0;
}