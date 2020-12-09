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
bool ps(string str){
    bool flag = true;
    stack<char> st;
    for(int j=0;j<str.size();j++){
        if(str[j]=='('){
            st.push(str[j]);
        }else if(str[j]==')' && !st.empty()){
            st.pop();
        }else if(str[j]=')' && st.empty()){
            flag = false;
            break; // 제일 처음에 )이 들어와도 말이 안되니깐 반복문에서 나감
        }
    }
    //만약 스택안에 ( 이 남아있어도 문제
    if(!st.empty()){
        flag=false;
    }
    return flag;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    string str;
    for(int i=0;i<T;i++){
        cin>>str;
        if(ps(str)==true){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}