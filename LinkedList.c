//
//  main.c
//  LinkedList
//
//  Created by Brett Fazio on 5/5/18.
//  Copyright © 2018 Brett Fazio. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct Node{
    void *data;
    
    struct Node *next;
};


void push(struct Node **head, void *data, size_t size) {

    struct Node *newBeginning = (struct Node *)malloc(sizeof(struct Node));
    
    newBeginning->data = malloc(size);
    
    newBeginning->next = (*head);
    
    int i = 0;
    for (i = 0; i < size; i++) {
        *(char*)(newBeginning->data+i) = *(char *)(data+i);
    }
    
    *head = newBeginning;
    
}

void printList(struct Node *head, void (*fptr)(void *)) {
    
    while (head != NULL) {
        (*fptr)(head->data);
        head = head->next;
    }
    
    printf("\n");
    
}

void printInt(void *data) {
    printf("%d ", *(int *)(data));
}


int main(int argc, const char * argv[]) {
    
    struct Node *linkedlist = NULL;
    
    unsigned int_size = sizeof(int);
    
    int arr[] = {5,10,15};
    int five = 5;
    push(&linkedlist, &arr[0], int_size);
    push(&linkedlist, &arr[1], int_size);
    push(&linkedlist, &arr[2], int_size);
    push(&linkedlist, &(five), int_size);

    
    printList(linkedlist, printInt);
    
    return 0;
}

