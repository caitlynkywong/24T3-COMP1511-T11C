// This program prints all the command-line arguments passed to it in reverse order.
// Written by William Setiawan
// and lightly edited by Caitlyn Wong, z5360361


#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    for (int i = argc - 1; i > 0; i--) {
        printf("Argument %d - ", i);
        for (int j = strlen(argv[i]) - 1; j >= 0; j--) {
            printf("%c", argv[i][j]);
        }
        printf("\n");
    }

    return 0;
}