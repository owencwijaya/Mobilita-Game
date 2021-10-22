#include <stdio.h>
#include "queue.c"

int main(){
    Queue q;
    int val = 0;
    CreateQueue(&q);
    isEmpty(q) ? printf("yes\n") : printf("no\n");
    for(int i = 0; i < CAPACITY; i++){
        enqueue(&q, i);
        displayQueue(q); 
        printf(" %d\n", length(q));
    }
    isFull(q) ? printf("yes\n") : printf("no\n");
    
    for(int i = 0; i < CAPACITY; i++){
        dequeue(&q, &val);
        displayQueue(q); 
        printf(" %d\n", length(q));
    }
    isEmpty(q) ? printf("yes\n") : printf("no\n");
    
}