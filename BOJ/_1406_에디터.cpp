#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <stack>
#include <queue>
#include <map>
#include <functional>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    char str[600000];
    cin>>str;
    stack<char> st;
    for(int i=0;i<strlen(str);i++){
        st.push(str[i]);
    }
    //커서를 기준으로 왼쪽 오른쪽 나눈다
    int M;
    cin>>M;
    
    stack<char> temp;
    for(int i=0;i<M;i++){
        char command;
        cin>>command;
        if(command=='P'){
            char value;
            cin>> value;
            st.push(value);
        }else if(command=='B'){
            if(!st.empty()){
                st.pop();                
            }
        }else if(command=='L'){
            if(!st.empty()){
                temp.push(st.top());
                st.pop();
            }
            
        }else if(command=='D'){
            if(!temp.empty()){
                st.push(temp.top());
                temp.pop();
            } 
        }
    }
    while(!st.empty()){
        temp.push(st.top());
        st.pop();
    }
    while(!temp.empty()){
        cout<<temp.top();
        temp.pop();
    }

    return 0;
}