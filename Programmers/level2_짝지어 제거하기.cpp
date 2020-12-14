#include <iostream>
#include<string>
#include <stack>
#include <algorithm>
using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<int> st;
    for(int i=0;i<s.size();i++){
        if(st.size()>0 && st.top()==s[i]){
            st.pop();
        }else{
            st.push(s[i]);
        }
    }
    if(st.empty()){
        answer = 1;
    }else{
        answer = 0;
    }

    return answer;
}