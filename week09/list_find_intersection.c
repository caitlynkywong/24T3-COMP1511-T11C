// list_find_intersection.c
// Written by Caitlyn Wong (z5360361) on April 2024
// This function takes in two linked lists and returns a new list that is
// constructed of nodes containing any values that appear in both lists


// Helper function to check if a value exists in a list
int exists_in_list(struct node *head, int data) {
    struct node *current = head;
    while (current != NULL) {
        if (current->data == data) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

// Function to find intersection of two lists
struct node *list_find_intersection(struct node *head1, struct node *head2) {
    // Initially, the resultant list is empty
    struct node *result = NULL;
    
    struct node *current1 = head1;
    while (current1 != NULL) {
        // Check if the value in the current node exists in the second list
        // and hasn't already been added to the resultant list
        if (
            exists_in_list(head2, current1->data) &&
            !exists_in_list(result, current1->data)
        ) {
            struct node *new_node = malloc(sizeof(struct node));
            new_node->data = data;
            new_node->next = NULL;
            
            if (result == NULL) {
                // If the resultant list is empty, make the new node the head
                result = new_node;
            } else {
                // Traverse the resultant list to add the new node at the tail
                struct node *current_res = result;
                while (current_res->next != NULL) {
                    current_res = current_res->next;
                }
                current_res->next = new_node;
            }
        }
        current1 = current1->next;
    }
    
    return result;
}