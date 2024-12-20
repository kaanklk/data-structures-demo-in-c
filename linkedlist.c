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
void removeLast(NodePtr *headNode);
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
    removeLast(&headNode);
    removeFirst(&headNode);

    // Print the linked list
    printList(headNode);

    // Free the linked list memory
    freeList(&headNode);

    return 0;
}

void removeFirst(NodePtr *headNode) {
    NodePtr tempNode = (NodePtr)malloc(sizeof(Node));
    tempNode = (*headNode)->next;
    *headNode = NULL;
    *headNode = tempNode;
}

void removeLast(NodePtr *headNode) {
    NodePtr currentNode = (NodePtr)malloc(sizeof(Node));
    NodePtr prevNode = (NodePtr)malloc(sizeof(Node));
    currentNode = (*headNode)->next;
    prevNode = (*headNode);

    if (currentNode == NULL)
    {
        return;
    }

    while(currentNode->next != NULL) {
        currentNode = currentNode->next;
        prevNode = prevNode->next;
    }

    currentNode = NULL;
    prevNode->next = NULL;
}

void append(int value, NodePtr *headNode, NodePtr *tailNode) {
    NodePtr tempNode = (NodePtr)malloc(sizeof(Node));
    if (tempNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    tempNode->value = value;
    tempNode->next = NULL;

    if (*headNode == NULL) { // List is empty
        *headNode = tempNode;
        *tailNode = tempNode;
    } else {
        (*tailNode)->next = tempNode;
        *tailNode = tempNode;
    }
}

void prepend(int value, NodePtr *headNode, NodePtr *tailNode) {
    NodePtr tempNode = (NodePtr)malloc(sizeof(Node));
    if (tempNode == NULL) {
        puts("Memory allocation failed!");
        return;
    }

    tempNode->value = value;
    tempNode->next = *headNode;

    *headNode = tempNode;
    if (*tailNode == NULL) { // If the list was empty
        *tailNode = tempNode;
    }
}

void printList(NodePtr headNode) {
    if (headNode == NULL) {
        puts("Nothing to print");
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
