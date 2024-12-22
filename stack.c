#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *prev;
};

typedef struct node Node;
typedef Node *NodePtr;

/* Function protoypes */
int push(int value, NodePtr *headNode);
int pop(NodePtr *headNode);

int main(int argc, char const *argv[])
{
    /* 
        As the head node moves upwards when new element is pushed,
        base stays still. When an element is pops, head moves downwards,
        base stays silll until no elements are left in the stack.
    */
    NodePtr headNode = NULL;

    push(5,&headNode);
    printf("Head node value: %d\n", headNode->value);
    
    push(12,&headNode);
    printf("Head node value: %d\n", headNode->value);

    push(88,&headNode);
    printf("Head node value: %d\n", headNode->value);

    push(42,&headNode);
    printf("Head node value: %d\n", headNode->value);
    
    pop(&headNode);
    printf("Head node value: %d\n", headNode->value);

    return 0;
}

int push(int value, NodePtr *headNode) {
    NodePtr newNode = malloc(sizeof(Node));
    if (newNode == NULL)
    {
        puts("Memory allocation failed!");
        return -1; 
    }

    newNode->value = value;
    newNode->prev = *headNode;
    *headNode = newNode;

    return 0;
}

int pop(NodePtr *headNode) {
    if (*headNode == NULL)
    {
        puts("List is empty!");
        return -1;
    }

    int poppedValue = (*headNode)->value;
    NodePtr prevNode = (*headNode)->prev;
    free(*headNode);
    *headNode = prevNode;
    return 0;
}


