#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

typedef struct node Node;
typedef Node *NodePtr;

// Function Prototypes
void prepend(int value, NodePtr *headNode, NodePtr *tailNode);
void append(int value, NodePtr *headNode, NodePtr *tailNode);
void removeLast(NodePtr *headNode,NodePtr *tailNode);
void removeFirst(NodePtr *headNode);
void printList(NodePtr headNode);
void freeList(NodePtr *headNode);

int main(void) {
    NodePtr headNode = NULL;
    NodePtr tailNode = NULL;

    // Insert values into the linked list
    append(31, &headNode, &tailNode);
    append(69, &headNode, &tailNode);
    prepend(1, &headNode, &tailNode);
    append(3, &headNode, &tailNode);
    prepend(5, &headNode, &tailNode);
    append(7,&headNode, &tailNode);
    removeLast(&headNode, &tailNode);
    removeFirst(&headNode);

    // Print the linked list
    printList(headNode);

    // Free the linked list memory
    freeList(&headNode);

    return 0;
}

void removeFirst(NodePtr *headNode) {
    if (*headNode == NULL)
    {
        puts("List is empty.");
        return;
    }
    
    NodePtr tempNode = *headNode;
    *headNode = (*headNode)->next;
    free(tempNode);
}

void removeLast(NodePtr *headNode, NodePtr *tailNode) {
    if (*headNode == NULL)
    {
        puts("List is empty.");
        return;
    }

    if ((*headNode)->next == NULL)
    {
        free(*headNode);
        *headNode = NULL;
        *tailNode = NULL;
        return;
    }

    NodePtr prevNode = NULL;
    NodePtr currentNode = *headNode;

    while(currentNode->next != NULL) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }

    free(currentNode);
    prevNode->next = NULL;
    *tailNode = prevNode;
}

void append(int value, NodePtr *headNode, NodePtr *tailNode) {
    NodePtr newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        puts("Memory allocation failed!");
        return;
    }

    newNode->value = value;
    newNode->next = NULL;

    if (*headNode == NULL) { // List is empty
        *headNode = newNode;
        *tailNode = newNode;
    } else {
        (*tailNode)->next = newNode;
        *tailNode = newNode;
    }
}

void prepend(int value, NodePtr *headNode, NodePtr *tailNode) {
    NodePtr newNode  = malloc(sizeof(Node));
    if (newNode  == NULL) {
        puts("Memory allocation failed!");
        return;
    }

    newNode ->value = value;
    newNode ->next = *headNode;

    *headNode = newNode;
    if (*tailNode == NULL) { // If the list was empty
        *tailNode = newNode;
    }
}

void printList(NodePtr headNode) {
    if (headNode == NULL) {
        puts("Nothing to print.");
        return;
    }

    NodePtr tempNode = headNode;
    while (tempNode != NULL) {
        printf("%d\n", tempNode->value);
        tempNode = tempNode->next;
    }
}

void freeList(NodePtr *headNode) {
    NodePtr current = *headNode;
    NodePtr nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    *headNode = NULL;
}
