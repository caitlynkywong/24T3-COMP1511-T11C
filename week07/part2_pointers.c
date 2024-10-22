// part2_pointers.c
//
// This program was written by T11C,
// on 22/10/2024
//
// This program uses pointers to halve three numbers


#include <stdio.h>

void halve_values(int *num_1_ptr, int *num_2_ptr, int *num_3_ptr);

int main(void) {
    int num_1 = 4;
    int num_2 = 10;
    int num_3 = 16;

    printf("Values before halved: \n");
    printf("Num 1: %d\n", num_1);
    printf("Num 2: %d\n", num_2);
    printf("Num 3: %d\n", num_3);

    halve_values(&num_1, &num_2, &num_3);

    printf("Values after halved: \n");
    printf("Num 1: %d\n", num_1);
    printf("Num 2: %d\n", num_2);
    printf("Num 3: %d\n", num_3);

    return 0;
}

void halve_values(int *num_1_ptr, int *num_2_ptr, int *num_3_ptr) {
    *num_1_ptr = *num_1_ptr / 2;
    *num_2_ptr = *num_2_ptr / 2;
    *num_3_ptr = *num_3_ptr / 2;
}