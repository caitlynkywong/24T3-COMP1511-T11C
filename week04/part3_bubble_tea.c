// part3_bubble_tea.c
//
// Written by Sofia De Bellis (z5418801) on March 2024
// and lightly edited by Caitlyn Wong (z5360361)
//
// This program is a simple bubble tea store used to teach functions


#include <stdio.h>

#define LARGE 'L'
#define REGULAR 'R'
#define BASE_COST 6.5
#define ADDED_COST 0.5
#define BASE_TEA 10
#define BASE_TOPPINGS 5

// enum definitions
enum bubble_tea_type {
    MILK_TEA,
    FRUIT_TEA,
    TARO_MILK,
    MATCHA_LATTE,
};

enum topping_types {
    TAPIOCA_PEARLS,
    JELLY,
    POPPING_PEARLS,
    ALOE_VERA,
};

// struct definitions
struct bubble_tea {
    enum bubble_tea_type type;
	enum topping_types topping;
	int topping_qty;
    char size;
};

struct inventory {
    int tea;
    int toppings;
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////// FUNCTION PROTOYPES //////////////////////////////
////////////////////////////////////////////////////////////////////////////////

struct bubble_tea scan_order(void);

int check_stock(struct bubble_tea order, struct inventory inventory);

double calculate_cost(struct bubble_tea order);

void print_order(struct bubble_tea order, double total_cost);

struct inventory update_stock(struct bubble_tea order, struct inventory inventory);

void print_inventory(struct inventory inventory);

////////////////////////////////////////////////////////////////////////////////
////////////////////////////// MAIN FUCNTION ///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int main(void) {
    struct inventory inventory;
    inventory.tea = BASE_TEA;
    inventory.toppings = BASE_TOPPINGS;

    // Step 1: Scan user's bubble tea order
    struct bubble_tea order = scan_order();

    // Step 2: Check available stock
    if (check_stock(order, inventory) == 1) {
        printf("Sorry, we cannot fulfil your bubble tea order due to "
                "insufficient stock.\n");
        return 1; 
    }

    // Step 3: Calculate the cost
    double total_cost = calculate_cost(order);

    // Step 4: Print the final order and cost
    print_order(order, total_cost);

    // Step 5: Update the stock after fulfilling the order
    inventory = update_stock(order, inventory);

    // Step 6: Print the remaining inventory
    print_inventory(inventory);

    return 0;
}

////////////////////////////////////////////////////////////////////////////////
///////////////////////////// FUNCTION DEFINITIONS /////////////////////////////
////////////////////////////////////////////////////////////////////////////////

/**
 * Takes a user's order
 * Params: None
 * Returns: order (struct bubble_tea)
*/
struct bubble_tea scan_order(void) {
    struct bubble_tea order;
    int type;

    printf("Enter bubble tea type (0: MILK TEA, 1: FRUIT TEA, 2: TARO MILK, "
            "3: MATCHA LATTE): ");
    scanf("%d", &type);
    if (type == 0) {
        order.type = MILK_TEA;
    } else if (type == 1) {
        order.type = FRUIT_TEA;
    } else if (type == 2) {
        order.type = TARO_MILK;
    } else if (type == 3) {
        order.type = MATCHA_LATTE;
    }

    printf("Enter topping (0: TAPIOCA PEARLS, 1: JELLY, 2: POPPING PEARLS, "
            "3: ALOE VERA): ");
    scanf("%d", &type);
    if (type == 0) {
        order.topping = TAPIOCA_PEARLS;
    } else if (type == 1) {
        order.topping = JELLY;
    } else if (type == 2) {
        order.topping = POPPING_PEARLS;
    } else if (type == 3) {
        order.topping = ALOE_VERA;
    }

    printf("Enter topping qty: ");
    scanf("%d", &order.topping_qty);

    printf("Enter size (L for Large, R for Regular): ");
    scanf(" %c", &order.size);

    return order;
}

/**
 * Checks if there is enough stock to fulfil an order
 * Params: order, inventory
 * Returns: 1 if insufficent stock, 0 is sufficient (int)
*/
int check_stock(struct bubble_tea order, struct inventory inventory) {
    if (inventory.tea - 1 < 0 ||
        inventory.toppings - order.topping_qty < 0) {
        return 1;
    } 

    return 0;
}

/**
 * Calculates the total cost of an order
 * Params: order
 * Returns: total cost of the order (double)
*/
double calculate_cost(struct bubble_tea order) {
    double total_cost = BASE_COST;

    if (order.size == LARGE) {
        total_cost += ADDED_COST;
    }

    if (order.type == MILK_TEA ||
        order.type == TARO_MILK ||
        order.type == MATCHA_LATTE) {
        total_cost += ADDED_COST;
    }

    int count = 0;
    while (count < order.topping_qty) {
        total_cost += ADDED_COST;
        count++;
    }

    return total_cost;
}

/**
 * Outputs a user's order and the total cost of that order
 * Params: order, total_cost
 * Returns: None
*/
void print_order(struct bubble_tea order, double total_cost) {
    printf("Order:\n");
    printf("Type: %d\n", order.type);
    printf("Topping Qty: %d\n", order.topping_qty);
    printf("Size: %c\n", order.size);
    printf("Total Cost: %.2lf\n", total_cost);
}

/**
 * Updates the inventory after an order is fulfilled
 * Params: order, inventory
 * Returns: new inventory stock levels (struct inventory)
*/
struct inventory update_stock(struct bubble_tea order, 
                              struct inventory inventory) {
    if (order.size == LARGE) {
        inventory.tea -= 2;
    } else {
        inventory.tea -= 1;
    }
            
    inventory.toppings -= order.topping_qty;

    return inventory;
}

/**
 * Outputs the total stock levels
 * Params: inventory
 * Returns: None
*/
void print_inventory(struct inventory inventory) {
    printf("The current inventory is: ");
    printf("Bubble tea(s): %d\n", inventory.tea);
    printf("Topping(s): %d\n", inventory.toppings);
    return;
}