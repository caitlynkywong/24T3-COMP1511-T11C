// Farmer's Farm
// part1_farm.c
//
// This program was written by T11C
// on 08/10/2024
//
// This program is a simple game that allows the user to build a farm.
// The user can place barns, trees, and coops in the farm.


#include <stdio.h>


#define SIZE 5
#define TREE_POINTS -10


enum entity_type {
    COOP,
    BARN,
    TREE,
    FARMER,
    EMPTY,
};

struct farm_entity {
    enum entity_type entity;
    int points;
};

struct player {
    int row;
    int col;
};


void print_farm(struct farm_entity farm[SIZE][SIZE]);
void initialise_farm(struct farm_entity farm[SIZE][SIZE]);
struct player place_farmer(struct farm_entity farm[SIZE][SIZE]);


int main(void) {
    struct farm_entity farm[SIZE][SIZE];

    // Initialise the farm
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            farm[i][j].entity = EMPTY;
            farm[i][j].points = 0;
        }
    }

    // Place the barns and trees in the farm
    printf("Enter barns and trees:\n");

    char type;
    scanf(" %c", &type);

    while (type != 'q') {
        int row;
        int col;
        scanf("%d %d", &row, &col);

        if (type == 'b') {
            int points;
            scanf("%d", &points);
            farm[row][col].entity = BARN;
            farm[row][col].points = points;
        } else if (type == 't') {
            farm[row][col].entity = TREE;
            farm[row][col].points = TREE_POINTS;
        }

        scanf(" %c", &type);
    }

    // Place the farmer in the farm
    printf("Enter the starting position of the farmer: ");

    struct player farmer;
    scanf("%d %d", &farmer.row, &farmer.col);

    while (farmer.row < 0 || farmer.row >= SIZE || farmer.col < 0 ||
           farmer.col >= SIZE || farm[farmer.row][farmer.col].entity != EMPTY) {
        printf("Invalid starting position!\n");
        printf("Re-enter starting position: ");
        scanf("%d %d", &farmer.row, &farmer.col);
    }

    farm[farmer.row][farmer.col].entity = FARMER;

    // Place the coops in the farm
    printf("Enter the position and points of the coop(s):\n");

    int coop_row;
    int coop_col;
    int coop_points;
    while (scanf("%d %d %d", &coop_row, &coop_col, &coop_points) == 3) {
        farm[coop_row][coop_col].entity = COOP;
        farm[coop_row][coop_col].points = coop_points;
    }

    // Print the farm
    print_farm(farm);

    return 0;
}


// Function prints the map of the farm
//
// Parameters:
// - farm: the 2D array representing the farm
//
// returns: nothing
void print_farm(struct farm_entity farm[SIZE][SIZE]) {
    printf("\n---------------------\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("|");
            if (farm[i][j].entity == FARMER) {
                printf(" X ");
            } else if (farm[i][j].entity == EMPTY) {
                printf("   ");
            } else if (farm[i][j].entity == COOP) {
                printf(" o ");
            } else if (farm[i][j].entity == BARN) {
                printf(" # ");
            } else if (farm[i][j].entity == TREE) {
                printf(" T ");
            }
        }
        printf("|\n");
        printf("---------------------\n");
    }
}
