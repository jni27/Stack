#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class AdvanceStack{
    public:
        stack<int> minStack;
        stack<int> elementStack;
        void push(int);
        void pop();
        int getMinimum();
};
void AdvanceStack :: push(int data){
    if(minStack.empty()){
        minStack.push(data);
        elementStack.push(data);
    }
    else if(data >= minStack.top()){
        elementStack.push(data);
    }
    else{
        minStack.push(data);
        elementStack.push(data);
    } 
}
void AdvanceStack :: pop(){
    int temp;
    if(elementStack.empty() || minStack.empty()){
         cout<<"Stack is Empty\n";
    }  
    // if(elementStack.top() > minStack.top()){
    //     temp = elementStack.top();
    //     elementStack.pop();
    //     cout<<"Popped Element "<<temp<<endl;
    //}
    else if(elementStack.top() == minStack.top()){
        temp = minStack.top();
        cout<<"Popped Element "<<temp<<endl;
        elementStack.pop();
        minStack.pop();
    }
    else{
        temp = elementStack.top();
        cout<<"Popped Element "<<temp<<endl;
        elementStack.pop();
    }
}

int AdvanceStack :: getMinimum(){
    return minStack.top();
}

int main(){
    AdvanceStack s;
    s.push(2);
    s.push(6);
    s.push(4);
    s.push(1);
    s.push(5);
    cout<<"Minimum element "<<s.getMinimum()<<endl;
    s.pop();
    s.pop();
    cout<<"Minimum element "<<s.getMinimum()<<endl;
}