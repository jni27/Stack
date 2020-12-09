#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

int scanNum(char ch){
    char value = ch;
    return (value - '0');
}

int isOperator(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    // if(c == '*' || c == '/')
    //     return 2;
    return -1;
}

int isOperand(char c){
    if(c >= '0' && c <= '9')
        return 1;
    return -1;
}

int operation(int a, int b, char op){
    if(op == '+')
        return b+a;
    else if(op == '-')
        return b-a;
    else if(op == '*')
        return b*a;
    else if(op == '/')
        return b/a;
    else if(op == '^')
        return pow(b,a);
    
    else return INT_MIN;
}
int infixEval(string exp){
    int x,y;
    char op;
    stack<int> values;
    stack<char> ops;
    string :: iterator i;
    for(i = exp.begin(); i < exp.end(); i++){
        // if(*i == " ")
        //     continue;
        if(isOperand(*i) > 0)
            values.push(scanNum(*i));

        else if(isOperator(*i) != -1 || *i == '(')
            ops.push(*i);
    
        else if(*i == ')'){
            while(!ops.empty() && ops.top() != '('){
                op = ops.top();
                ops.pop();
                x = values.top();
                values.pop();
                y = values.top();
                values.pop(); 
                values.push(operation(x, y, op));
            }
        if(!ops.empty())
            ops.pop();
        }
    }
    while(!ops.empty()){
        op = ops.top();
        ops.pop();
        x = values.top();
        values.pop();
        y = values.top();
        values.pop(); 
        values.push(operation(x, y, op));
    }
    return values.top();
}

int main(){
    string s = "(5+7)/(3*2)+6";
    cout<<"Infix expression "<<s<<endl;

    cout<<"Result "<<infixEval(s)<<endl;
}