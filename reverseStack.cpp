#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void insertAtBottom(stack <int> &s, int data){
    int temp;
    if(s.empty()){
        s.push(data);
    }else{
        temp= s.top();
        s.pop();
        insertAtBottom(s,data);
        s.push(temp);
    }   
}

void reverse(stack <int> &s){
    int data;

    if(s.empty()){
        return;
    }else{
        data= s.top();
        s.pop();
        reverse(s);
        insertAtBottom(s,data);    
    }
}

int main(){
    stack <int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout<<"Original stack top element"<<" ";
    cout<<st.top()<<endl;

    reverse(st);
    cout<<"Reversed Stack top element"<<" ";
    cout<<st.top()<<endl;
    cout<<"Reversed Stack"<<" ";
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    

}