#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <functional>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    stack<int> st;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        if(str=="push"){
            int n;
            cin>>n;
            st.push(n);
        }
        if(str=="pop"){
            if(!st.empty()){
                cout<<st.top()<<'\n';
                st.pop();
            }else{
                cout<<-1<<'\n';
            }
        }
        if(str=="top"){
            if(!st.empty()){
                cout<<st.top()<<'\n';
            }else{
                cout<<-1<<'\n';
            }
        }
        if(str=="size"){
            cout<<st.size()<<'\n';
        }
        if(str=="empty"){
            if(st.empty()){
                cout<<1<<'\n';
            }else{
                cout<<0<<'\n';
            }
        }
    }
    

    return 0;
}