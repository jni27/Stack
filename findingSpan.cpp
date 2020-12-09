#include<iostream>
#include<vector>
#include<stack>

using namespace std;
vector<int> span;
stack<int> st;
void print(vector<int> &a){
    for(auto i=a.begin() ;i != a.end(); i++){
        cout<<*i<<" ";
    }
    cout<<endl;
}
void findSpan(vector<int> &vt, int n){
    st.push(0);
    for(int i=0; i<n; i++){
        while(!st.empty() && vt[st.top()] <= vt[i]){
            st.pop();
        }
        if(st.empty()){
            span.push_back(i+1);
        }
        else{
            span.push_back(i - st.top());
        }
        st.push(i);
    }
}

int main(){
    vector<int> v;
    int n;
    cout<<"Enter size ";
    cin>>n;
    cout<<"Enter numbers ";
    for(int i=0; i<n; i++){
        int input;
        cin>>input;
        v.push_back(input);
    }
    cout<<"Data ";
    print(v);
    findSpan(v, n);
    cout<<"Span ";
    print(span);
    return 0;
}
