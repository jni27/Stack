#include<stdio.h>
#include<stdlib.h>

struct DynStack{
    int top;
    int capacity;
    int *array;
};

struct DynStack *CreateStack(){
    struct DynStack *s = malloc(sizeof(struct DynStack));
    if(!s)
        return NULL;
    s->top = -1;
    s->capacity = 1;
    s->array = (int *)malloc(s->capacity * sizeof(int)); //allocate array of size 1 initially
    if(!s->array)
        return NULL;
    return s;
}

int isFull(struct DynStack *s){
    return s->top == s->capacity-1;
}

void DoubleStack(struct DynStack *s){
    s->capacity *= 2;
    s->array = realloc(s->array, s->capacity * sizeof(int));
}

void Push(struct DynStack *s, int x){
    //No overflow in this implementation
    if(isFull(s))
        DoubleStack(s);
    s->array[++s->top] = x;
    printf("%d pushed into stack.\n", s->array[s->top]);
}

int isEmpty(struct DynStack *s){
    return s->top == -1;
}

int Top(struct DynStack *s){
    if(isEmpty(s))
        printf("Stack is  Empty\n");
    return s->array[s->top];
}

int Pop(struct DynStack *s){
    if(isEmpty(s))
        printf("Underflow\n");
    return s->array[s->top--];
}

int main(){
    struct DynStack *st = CreateStack();
    Push(st, 10);
    Push(st, 20);
    Push(st, 30);
    printf("Popped Element %d\n", Pop(st));
}