#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

int scanNum(char ch){
    char val = ch;
    return int(val - '0');
}

int isOperator(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return 1;
    return -1;
}
int isOperand(char c){
    if(c >= '0' && c<='9')
        return 1;
    return -1;
}
int operation(int a, int b, char op){
    if(op == '+')
        return b + a;
    else if(op == '-')
        return b - a;
    else if(op == '*')
        return b * a;
    else if(op == '/')
        return b / a;
    else if(op == '^')
        return pow(b , a);

    else return INT_MIN;
}
int postfixEval(string exp){
    int a, b;
    stack<int> st;
    string :: iterator i;
    for(i = exp.begin(); i < exp.end(); i++){
        if(isOperator(*i) != -1){
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(operation(a, b, *i));
        } 
        else if(isOperand(*i) > 0){
            st.push(scanNum(*i));
        }
    }
    return st.top();    
}
int main(){
    string postfix  = "2 3 1 * + 9 -";
    cout<<"Postfix expression "<<postfix<<endl;
    
    cout<<"The result is "<<postfixEval(postfix)<<endl;
}