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
    string str;
    cin>>str;
    int answer = 0;
    stack <int> st;
    for(int i=0;i<str.size();i++){
        if(str[i]=='('){
            st.push(i);
        }else if(str[i]==')'){
            if(st.top()+1==i){
                st.pop();
                answer +=st.size();
            }else{
                st.pop();
                answer+=1;
            }
        }
        
    }
    cout<<answer;
    return 0;
}