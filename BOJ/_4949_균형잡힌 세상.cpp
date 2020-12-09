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
stack<char> st;
bool ps(string str){
    bool flag = true;
    for(int i=0;i<str.size();i++){
        if(str[i]=='(' || str[i]=='['){
            st.push(str[i]);
        }else if(str[i]==')' && !st.empty()){
            if(st.top()=='('){
                st.pop();
            }else if(st.top()=='['){
                flag = false;
                break;
            }
        }else if(str[i]==']' && !st.empty()){
            if(st.top()=='['){
                st.pop();
            }else if(st.top()=='('){
                flag=false;
                break;
            }
        }else if( (str[i]==']' || str[i]==')') && st.empty()){
            flag=false;
            break;
        }
    }
        if(!st.empty()){
            flag=false;
        }
        return flag;
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    string str;
    while(true){
        getline(cin,str); //공백까지 입력받으려면 getline 사용
        if(str.length()==1 && str[0]=='.'){
            break;
        }
        while(!st.empty()){ //문장마다 스택을 초기화
            st.pop();
        }
        if(ps(str)==true){
            cout<<"yes"<<endl;
        }else{
            cout<<"no"<<endl;
        }
    }
    return 0;
}