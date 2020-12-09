#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

bool parenthesis(string exp){
    stack<char> s;
    char t;
    for(int i=0; i<exp.length(); i++){
        if(exp[i] == '[' || exp[i] == '{' || exp[i] == '('){
            s.push(exp[i]);
            continue;
        }

        if(s.empty())
            return false;
    
        switch(exp[i]){
            case ')' : t = s.top();
                        s.pop();
                        if(t == '{' || t == '[')
                            return false;
                        break;
            case '}' : t = s.top();
                        s.pop();
                        if(t == '(' || t == '[')
                            return false;
                        break;
            case ']' : t = s.top();
                        s.pop();
                        if(t == '{' || t == '(')
                            return false;
                        break;
        }
    }
    return (s.empty());
}

int main(){
    string s;
    cout<<"Enter parenthesis pattern ";
    cin>>s; //[({)}]
    if(parenthesis(s))
        cout<<"Balanced\n";
    else
        cout<<"Not Balanced\n";
    
    return 0;
}
