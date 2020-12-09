#include<stdio.h>
#include<stdlib.h>

struct ListStack{
    int data; 
    struct ListStack  *next;
};

void Push(struct ListStack **top, int data){
    struct ListStack *temp;
    temp = malloc(sizeof(struct ListStack));
    if(!temp)
        printf("NULL\n");
    temp->data = data;
    temp->next = *top;
    *top = temp;
    printf("%d is pushed into stack.\n", temp->data);
}

int isEmpty(struct ListStack *top){
    return top == NULL;
}

int Pop(struct ListStack **top){
    struct ListStack *temp, *p;
    int item;
    if(isEmpty(*top))
        printf("Stack Underflow\n");
    temp = *top;
    p = *top;
    p = p->next;
    item = temp->data;
    free(temp);
    return item;
}

int Top(struct ListStack *top){
    if(isEmpty(top)){
        printf("Empty Stack\n");
    }
    return top->data;
}

// void DeleteStack(struct ListStack **top){





// }
int main(){
    struct ListStack *top = NULL;
    Push(&top, 10);
    Push(&top, 20);
    Push(&top, 30);
    printf("Popped Element %d\n", Pop(&top));
}