#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

int isPalindrome(char *C){
    stack <char> s;
    int i=0;

    while(C[i] != 'X'){
        s.push(C[i]);
        i++;
    }
    i++;   
    
    while(C[i] != '\0'){
        if(C[i] != s.top() || s.empty()){
            // cout<<s.top()<<" ";
            return 0;
            break;
        }else{
            s.pop();
        }
        i++;
    }
    return 1;
}

int main(){
    char ch[] = "abchkssXsskhcba";
    if(isPalindrome(ch)){
        cout<<"Palindrome\n";
    }else{
        cout<<"NOT Palindrome\n";
    }
}