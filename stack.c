#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *prev;
};

typedef struct node Node;
typedef Node *NodePtr;

struct stack {
    Node *head;
};

typedef struct stack Stack;
typedef Stack *StackPtr;

/* Function protoypes */
StackPtr initStack();
int push(int value, StackPtr stackPtr);
int pop(StackPtr stackPtr);
void destroyStack(StackPtr StackPtr);

int main(int argc, char const *argv[])
{
    /* 
        The headNode pointer is updated to point to the new node when an element is pushed,
        effectively moving "up" the stack. When an element is popped, headNode is updated 
        to point to the previous node, moving "down" the stack.
    */
    StackPtr sampleStack = initStack();

    push(5, sampleStack);
    printf("Head node value: %d\n", sampleStack->head->value);
    
    push(12, sampleStack);
    printf("Head node value: %d\n", sampleStack->head->value);

    push(88, sampleStack);
    printf("Head node value: %d\n", sampleStack->head->value);

    push(42, sampleStack);
    printf("Head node value: %d\n", sampleStack->head->value);
    
    pop(sampleStack);
    printf("Head node value: %d\n", sampleStack->head->value);

    destroyStack(sampleStack);

    return 0;
}

StackPtr initStack() {
    StackPtr newStack = malloc(sizeof(Stack));
    if (newStack == NULL)
    {
        puts("Memory allocation failed!");
        return NULL;
    }
    
    newStack->head = NULL;
    return newStack;
}

int push(int value, StackPtr stackPtr) {
    NodePtr newNode = malloc(sizeof(Node));
    if (newNode == NULL)
    {
        puts("Memory allocation failed!");
        return -1; 
    }

    newNode->value = value;
    newNode->prev = stackPtr->head;
    stackPtr->head = newNode;

    return 0;
}

int pop(StackPtr stackPtr) {
    if (stackPtr->head == NULL)
    {
        puts("List is empty!");
        return -1;
    }

    int poppedValue = stackPtr->head->value;
    NodePtr prevNode = stackPtr->head->prev;
    free(stackPtr->head);
    stackPtr->head = prevNode;
    return 0;
}

void destroyStack(StackPtr stackPtr) {
    if (!stackPtr) return;
    while (stackPtr->head != NULL) {
        NodePtr temp = stackPtr->head;
        stackPtr->head = stackPtr->head->prev;
        free(temp);
    }
    free(stackPtr);
}


