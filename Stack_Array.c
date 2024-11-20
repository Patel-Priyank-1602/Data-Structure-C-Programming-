#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int *array;
    int top;
    int capacity;
};

struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    if (!stack->array) {
        printf("Memory allocation failed!\n");
        free(stack);
        return NULL;
    }
    return stack;
}

void push(struct Stack* stack, int value) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack overflow! Cannot push %d\n", value);
    } else {
        stack->top++;
        stack->array[stack->top] = value;
        printf("Pushed %d to the stack\n", value);
    }
}

int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow! Cannot pop\n");
        return -1;
    } else {
        int poppedValue = stack->array[stack->top];
        stack->top--;
        printf("Popped %d from the stack\n", poppedValue);
        return poppedValue;
    }
}

int peek(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty!\n");
        return -1;
    } else {
        return stack->array[stack->top];
    }
}

void display(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements are: ");
        for (int i = stack->top; i >= 0; i--) {
            printf("%d ", stack->array[i]);
        }
        printf("\n");
    }
}

int main() {
    int capacity;
    printf("Enter the capacity of the stack: ");
    scanf("%d", &capacity);

    struct Stack* stack = createStack(capacity);
    if (!stack) return 1; 

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    display(stack);

    printf("Top element is %d\n", peek(stack)); 
    pop(stack);
    display(stack); 

}
