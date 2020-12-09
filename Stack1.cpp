#include<iostream>
using namespace std;

#define MAX 100

class Stack{
    int top;
    public:
        int a[MAX];
        Stack() {top = -1;}
        bool isEmpty();
        bool isFull();
        void push(int data);
        int pop();
        int peek();
};

bool Stack :: isEmpty(){
        return (top < 0);
}

bool Stack :: isFull(){
    return (top >= MAX-1);
}

void Stack :: push(int data){
    if(isFull())    
        cout<<"Stack Overflow\n";
    else{
        a[++top] = data;
        cout<<data<<" is pushed into stack\n";
    }
}

int Stack :: pop(){
    if(isEmpty()){
        cout<<"Underflow\n";
    }
    return a[top--];
}

int Stack :: peek(){
    if(isEmpty()){
        cout<<"Stack is Empty";
        return 0;
    }
    else{
        return a[top];
    }  
}

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.pop()<<" Poopped from stack\n";
}


