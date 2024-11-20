#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int *array;
    int front, rear;
    int capacity;
};

struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    if (!queue->array) {
        printf("Memory allocation failed!\n");
        free(queue);
        return NULL;
    }
    return queue;
}

int isFull(struct Queue* queue) {
    return (queue->rear == queue->capacity - 1);
}

int isEmpty(struct Queue* queue) {
    return (queue->front == -1 || queue->rear == -1);
}

void enqueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue overflow! Cannot enqueue %d\n", value);
    } else {
        if (queue->front == -1) queue->front = 0;  
        queue->rear++;
        queue->array[queue->rear] = value;
        printf("Enqueued %d to the queue\n", value);
    }
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow! Cannot dequeue\n");
        return -1;
    } else {
        int dequeuedValue = queue->array[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
        printf("Dequeued %d from the queue\n", dequeuedValue);
        return dequeuedValue;
    }
}

int peek(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        return queue->array[queue->front];
    }
}

void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements are: ");
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->array[i]);
        }
        printf("\n");
    }
}

int main() {
    int capacity;
    printf("Enter the capacity of the queue: ");
    scanf("%d", &capacity);

    struct Queue* queue = createQueue(capacity);
    if (!queue) return 1; 

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    display(queue);

    printf("Front element is %d\n", peek(queue));
    dequeue(queue);
    display(queue);
}
