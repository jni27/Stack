//Program to implement two stack using only one array
#include<iostream>
using namespace std;
#define SIZE 10

class twoStacks{
    int *arr;
    int size;
    int top1, top2;

    public:
        twoStacks(int n){
            size = n;
            arr = new int[n];
            top1 = -1;
            top2 = size;

        } 
        void push1(int x1);
        void push2(int x2);
        int pop1();
        int pop2();  
};

void twoStacks :: push1(int data){
    if(top1 < top2 - 1){
        arr[++top1] = data;
    }else{
        cout<<"Stack overflow"<<endl;
    }
}
void twoStacks :: push2(int data){
    if(top1 < top2 - 1){
        arr[--top2] = data;
    }else{
        cout<<"Stack overflow"<<endl;
    }
}

int twoStacks :: pop1(){
    if(top1 == -1){
        cout<<"Stack underflow\n";
    }
    return arr[top1--];
    
}
int twoStacks :: pop2(){
    if(top2 == size-1){
        cout<<"Stack underflow\n";
    }
    return arr[top2++];

}

int main(){
    twoStacks ts(8);
    ts.push1(5); 
    ts.push2(10); 
    ts.push2(15); 
    ts.push1(11); 
    ts.push2(7); 
    cout << "Popped element from stack1 is "
         << ts.pop1(); 
    cout << "Popped element from stack1 is "
         << ts.pop1();

    ts.push2(40); 
    cout << "\nPopped element from stack2 is "
         << ts.pop2(); 
    cout<<"\n";
    return 0; 
}