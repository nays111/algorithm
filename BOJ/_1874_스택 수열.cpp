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
    int N;
    cin>>N;
    stack<int> st;
    int m=0;
    string answer;
    bool checked = true;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        if(a>m){//m은 가장 컸던 숫자를 의미
            while(a>m){
                st.push(++m);
                answer+='+';
            }
            st.pop();
            answer+='-';
        }else{
            if(st.top()==a){
                st.pop();
                answer+='-';
            }else{
                checked = false;
            }
        }
    }
    if(!checked){
            cout<<"NO";
    }else{
        for(int i=0;i<answer.size();i++){
            cout<<answer[i]<<'\n';
        }
    }
    

    return 0;
}