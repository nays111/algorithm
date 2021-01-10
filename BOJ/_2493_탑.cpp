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
    
    int n;
    stack<pair<int,int>> st;
    cin>>n;
    for(int i=1;i<=n;i++){
        int num;
        cin>>num;
        if(st.empty()){
            st.push(make_pair(i,num));
            cout<<0<<" ";
        }else{
            if(st.top().second <= num){
                while(!st.empty() && st.top().second<=num){
                    st.pop();
                }
                if(st.empty()){
                    cout<<0<<" ";
                }else{
                    cout<<st.top().first<<" ";
                }
                st.push(make_pair(i,num));
                
            }else{
                cout<<st.top().first<<" ";
                st.push(make_pair(i,num));
            }   
        }
    }


    return 0;
}