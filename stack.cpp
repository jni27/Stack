#include<iostream>
using namespace std;

#define MAXSIZE 10
class arrStack{
    public:
        int top;
        int capacity;
        int *array;
};

arrStack *createStack(){
    arrStack *S = new arrStack();
    if(!S)
        return NULL;
    S->capacity = MAXSIZE;
    S->top = -1;
    S->array = (int*)malloc(S->capacity * sizeof(int));
    if(!S->array)
        return NULL;
    return S;
}

int IsEmpty(arrStack *S){
    return (S->top == -1); //if the condition is true then return 1 else return 0
}

int IsFull(arrStack *S){
    return (S->top == S->capacity - 1); //if the condition is true then return 1 else return 0
}

void push(arrStack *S, int data){
    if(IsFull(S))
        cout<<"Stack Overflow\n";
    else{
        S->array[++S->top] = data;
        cout<<data<<" "<<"pushed to stack"<<endl;
    }      
}

int pop(arrStack *S){
    if(IsEmpty(S)){
        cout<<"Stack is Empty\n";
        return INT_MIN;
    }
    else{
        // S->top = (S->top) -1;
        // return (S->array[S->top]);
        // cout<<"Popped Element: "<<S->array[S->top]<<endl;
        return S->array[S->top--];
    }
}        

void display(arrStack *S){
    while(S->top != -1){
        cout<<S->array[S->top];
        S->top = (S->top) -1;
    }
}

// void DelStack(arrStack *S){
//     if(S){
//         if(S->array)
//             free(S->array);
//         free(S);
//     }
// }
int peek(arrStack *S){
    if(IsEmpty(S))
        return INT_MIN;
    return S->array[S->top];
}

int main(){
    arrStack *st = createStack();
    push(st, 10);
    push(st, 20);
    push(st, 30);
    cout<<pop(st)<<" popped from stack\n";
    cout<<peek(st)<<" stack top value \n";
    //display(st);
}
