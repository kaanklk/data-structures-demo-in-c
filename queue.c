#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

typedef struct node Node;
typedef Node *NodePtr;

struct queue {
    Node *head;
    Node *tail;
};

typedef struct queue Queue;
typedef Queue *QueuePtr;


/* Function prototypes*/
QueuePtr initQueue();
int enqueue(int value, QueuePtr queue);
int dequeue(QueuePtr queue);
int isEmpty(QueuePtr queue);
int peekHead(QueuePtr queue);
void destroyQueue(QueuePtr queue);

int main(int argc, char const *argv[])
{
    QueuePtr sampleQueue = initQueue();
    if (sampleQueue == NULL)
    {
        puts("Can't create queue!");
        return -1;
    }
    puts("Queue created successfully!");
    enqueue(5,sampleQueue);
    printf("Head: %d\n", peekHead(sampleQueue));
    enqueue(10,sampleQueue);
    printf("Head: %d\n", peekHead(sampleQueue));
    enqueue(42,sampleQueue);
    printf("Head: %d\n", peekHead(sampleQueue));
    dequeue(sampleQueue);
    printf("Head: %d\n", peekHead(sampleQueue));
    dequeue(sampleQueue);
    printf("Head: %d\n", peekHead(sampleQueue));
    
    return 0;
}

int peekHead(QueuePtr queue) {
    return (isEmpty(queue)) ? -1 : queue->head->value;
}

int isEmpty(QueuePtr queue) {
    return queue->head == NULL;
}

void destroyQueue(QueuePtr queue) {
    while (!isEmpty(queue))
    {
        dequeue(queue);
    }
    free(queue);
}

int dequeue(QueuePtr queue) {
    if (queue->head == NULL)
    {
        puts("Queue is empty!");
        return -1;
    }
    NodePtr nodeToBeDequeued = queue->head;
    int dequeuedValue = nodeToBeDequeued->value;
    queue->head = queue->head->next;

    /* If removed node was the last element, then set tail to NULL */
    if (queue->head == NULL)
    {
        queue->tail == NULL;
    }
    free(nodeToBeDequeued);
}

int enqueue(int value, QueuePtr queue) {
    NodePtr newNode = malloc(sizeof(Node));
    if (newNode == NULL)
    {
        puts("Memory allocation failed! Can not create new node!");
        return -1;
    }
    newNode->value = value;
    newNode->next = NULL;

    if (queue->tail == NULL)
    {
        queue->head = newNode;
        queue->tail = newNode;
    } else {
        /* Adding a new element to tail. */
        queue->tail->next = newNode;
        /* New tail is the new element. */
        queue->tail = newNode;
    }    

    return 0;
}

QueuePtr initQueue() {
    QueuePtr newQueue = malloc(sizeof(Queue));
    if (newQueue == NULL)
    {
        puts("Memory allocation failed!");
        return NULL;
    }
    
    newQueue->head = NULL;
    newQueue->tail = NULL;
    return newQueue;
}



