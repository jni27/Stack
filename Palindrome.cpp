#include<iostream>
#include<string>
using namespace std;

int isPalindrome(char *s){
    int i = 0;
    int j  = strlen(s) - 1;
    while(i<j && s[i] == s[j]){
        i++;
        j--;
    }
    if(i<j){
        cout<<"Not Palindrome\n";
        return 0;
    }else{
        cout<<"Palindrome\n";
        return 1;
    }
}
int main(){
    int p;
    char st[] = "racecar";
    p = isPalindrome(st);
}
