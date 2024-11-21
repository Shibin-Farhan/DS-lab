#include <stdio.h>
#include <stdlib.h>

// Definition of a node in a doubly linked list
struct Node {
    int data;                  // Data stored in the node
    struct Node* next;        // Pointer to the next node
    struct Node* prev;        // Pointer to the previous node
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for a new node
    newNode->data = data;  // Set the node's data
    newNode->next = NULL;  // Initialize next pointer to NULL
    newNode->prev = NULL;  // Initialize prev pointer to NULL
    return newNode;        // Return the newly created node
}

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data); // Create a new node
    newNode->next = *head;                    // Point new node's next to current head
    if (*head != NULL) {
        (*head)->prev = newNode;              // Update previous head's prev pointer
    }
    *head = newNode;                          // Update head to new node
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data); // Create a new node
    if (*head == NULL) {                      // If list is empty
        *head = newNode;                      // New node becomes the head
        return;
    }
    struct Node* temp = *head;                // Start from head
    while (temp->next != NULL) {              // Traverse to the last node
        temp = temp->next;
    }
    temp->next = newNode;                     // Link last node to new node
    newNode->prev = temp;                     // Set new node's previous pointer
}

// Function to insert a node at a specific position
void insertAtPosition(struct Node** head, int data, int position) {
    if (position == 0) {                       // If inserting at the beginning
        insertAtBeginning(head, data);
        return;
    }
    struct Node* newNode = createNode(data);  // Create a new node
    struct Node* temp = *head;                 // Start from head
    for (int i = 0; i < position - 1 && temp != NULL; i++) { // Traverse to the desired position
        temp = temp->next;
    }
    if (temp == NULL) {                        // Check if position is out of bounds
        printf("Position out of bounds\n");
        free(newNode);                         // Free allocated memory for new node
        return;
    }
    newNode->next = temp->next;               // Link new node's next to the next node
    newNode->prev = temp;                     // Link new node's prev to the current node
    if (temp->next != NULL) {                 // Update next node's prev if it exists
        temp->next->prev = newNode;
    }
    temp->next = newNode;                     // Link current node to new node
}

// Function to delete a node from the beginning
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {                       // Check if the list is empty
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;                 // Store the current head
    *head = (*head)->next;                     // Update head to the next node
    if (*head != NULL) {                       // If the new head is not NULL
        (*head)->prev = NULL;                  // Set its previous pointer to NULL
    }
    free(temp);                                // Free memory of the old head
}

// Function to delete a node from the end
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {                       // Check if the list is empty
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;                 // Start from head
    while (temp->next != NULL) {               // Traverse to the last node
        temp = temp->next;
    }
    if (temp->prev != NULL) {                  // If there is a previous node
        temp->prev->next = NULL;               // Update its next pointer
    } else {
        *head = NULL;                          // List is now empty
    }
    free(temp);                                // Free memory of the last node
}

// Function to delete a node from a specific position
void deleteFromPosition(struct Node** head, int position) {
    if (*head == NULL) {                       // Check if the list is empty
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;                 // Start from head
    if (position == 0) {                       // If deleting the first node
        deleteFromBeginning(head);
        return;
    }
    for (int i = 0; i < position && temp != NULL; i++) { // Traverse to the desired position
        temp = temp->next;
    }
    if (temp == NULL) {                        // Check if position is out of bounds
        printf("Position out of bounds\n");
        return;
    }
    if (temp->prev != NULL) {                  // Link previous node's next to the next node
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {                  // Link next node's prev to the previous node
        temp->next->prev = temp->prev;
    }
    free(temp);                                // Free memory of the node to be deleted
}

// Function to print the list
void printList(struct Node* head) {
    struct Node* temp = head;                  // Start from head
    while (temp != NULL) {                     // Traverse until the end
        printf("%d ", temp->data);             // Print node data
        temp = temp->next;                     // Move to the next node
    }
    printf("\n");
}

// Main function to test the implementation
int main() {
    struct Node* head = NULL;                  // Initialize the head of the list
    int choice, data, position;

    do {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Print List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);                  // Get user choice

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &position);
                insertAtPosition(&head, data, position);
                break;
            case 4:
                deleteFromBeginning(&head);
                printf("Deleted from beginning.\n");
                break;
            case 5:
                deleteFromEnd(&head);
                printf("Deleted from end.\n");
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteFromPosition(&head, position);
                break;
            case 7:
                printf("Current List: ");
                printList(head);
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 8);                     // Repeat until exit choice

    return 0;
}

