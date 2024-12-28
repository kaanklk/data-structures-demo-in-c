#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

typedef struct node Node;
typedef Node *NodePtr;

struct linkedList {
    Node *head;
    Node *tail;
};

typedef struct linkedList LinkedList;
typedef LinkedList *LinkedListPtr;

// Function Prototypes
LinkedListPtr initLinkedList();
void prepend(int value, LinkedListPtr linkedList);
void append(int value, LinkedListPtr linkedList);
void removeLast(LinkedListPtr linkedList);
void removeFirst(LinkedListPtr linkedList);
void printList(LinkedListPtr linkedList);
void freeList(LinkedListPtr linkedList);
int getListSize(LinkedListPtr linkedList);

int main(void) {
    LinkedListPtr sampleLinkedList = initLinkedList();

    // Insert values into the linked list
    append(31, sampleLinkedList);
    append(69, sampleLinkedList);
    prepend(1, sampleLinkedList);
    append(3, sampleLinkedList);
    prepend(5, sampleLinkedList);
    append(7, sampleLinkedList);
    removeLast(sampleLinkedList);
    removeFirst(sampleLinkedList);

    // Print the linked list
    printList(sampleLinkedList);
    printf("%s %d\n", "List size is:", getListSize(sampleLinkedList));

    // Free the linked list memory
    freeList(sampleLinkedList);
    printf("%s %d\n", "List size is:", getListSize(sampleLinkedList));

    return 0;
}

LinkedListPtr initLinkedList() {
    LinkedListPtr newLinkedList = malloc(sizeof(LinkedList));
    if (newLinkedList == NULL)
    {
        puts("Memory allocation failed!");
        return NULL;
    }
    newLinkedList->head = NULL;
    newLinkedList->tail = NULL;
    return newLinkedList;
}

int getListSize(LinkedListPtr linkedList) {
    int count = 0;
    NodePtr tempNode = linkedList->head;

    while (tempNode != NULL) {
        count++;
        tempNode = tempNode->next;
    }

    return count;
}

void removeFirst(LinkedListPtr linkedList) {
    if (linkedList->head == NULL)
    {
        puts("List is empty.");
        return;
    }
    
    NodePtr tempNode = linkedList->head;
    linkedList->head = linkedList->head->next;

    if (linkedList->head == NULL)
    {
        linkedList->tail = NULL;
    }

    free(tempNode);
}

void removeLast(LinkedListPtr linkedList) {

    if (linkedList->head == NULL)
    {
        puts("List is empty.");
        return;
    }

    if (linkedList->head == linkedList->tail)
    {
        free(linkedList->head);
        linkedList->head = NULL;
        linkedList->tail = NULL;
        return;
    }

    NodePtr prevNode = NULL;
    NodePtr currentNode = linkedList->head;

    while(currentNode->next != NULL) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }

    free(currentNode);
    prevNode->next = NULL;
    linkedList->tail = prevNode;
}

void append(int value, LinkedListPtr linkedList) {
    NodePtr newNode = malloc(sizeof(Node));

    if (newNode == NULL) {
        puts("Memory allocation failed!");
        return;
    }

    newNode->value = value;
    newNode->next = NULL;

    if (linkedList->head == NULL) { // List is empty
        linkedList->head = newNode;
        linkedList->tail = newNode;
    } else {
        linkedList->tail->next = newNode;
        linkedList->tail = newNode;
    }
}

void prepend(int value, LinkedListPtr linkedList) {
    NodePtr newNode  = malloc(sizeof(Node));
    if (newNode  == NULL) {
        puts("Memory allocation failed!");
        return;
    }

    newNode ->value = value;
    newNode ->next = linkedList->head;
    linkedList->head = newNode;

    if (linkedList->tail == NULL) { // If the list was empty
        linkedList->tail = newNode;
    }
}

void printList(LinkedListPtr linkedList) {
    if (linkedList->head == NULL) {
        puts("Nothing to print.");
        return;
    }

    NodePtr tempNode = linkedList->head;
    while (tempNode != NULL) {
        printf("%d\n", tempNode->value);
        tempNode = tempNode->next;
    }
}

void freeList(LinkedListPtr linkedList) {
    NodePtr current = linkedList->head;
    NodePtr nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    linkedList->head = NULL;
    linkedList->tail = NULL;
}
