//
//  Stack.c
//  DataStructures
//
//  Created by Brett Fazio on 5/5/18.
//  Copyright © 2018 Brett Fazio. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef struct Stack Stack;

struct Stack {
    void * stack[MAX_STACK_SIZE];
    int top;
};

void push(Stack * stack, void * item) {
    
    if (stack->top+1 >= MAX_STACK_SIZE) {
        printf("Stack is full");
        return;
    }
    
    stack->stack[stack->top++] = item;
    
}

void * pop(Stack * stack) {
    
    if (stack->top < 0) {
        printf("Stack is empty");
        return NULL;
    }
    
    return stack->stack[--stack->top];
}

Stack * makeStack() {
    Stack * ret = (Stack*)malloc(sizeof(Stack));
    
    ret->top = -1;
    
    // Below is to avoid NULL uncertainty.
    for (int i = 0; i < MAX_STACK_SIZE; i++) {
        ret->stack[i] = 0;
    }
    
    return ret;
}

// use "*(TYPE *)(pop(stack))" to print out or get the value.

