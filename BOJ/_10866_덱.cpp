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
    deque<int> dq;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        if(str=="push_back"){
            int num;
            cin>>num;
            dq.push_back(num);
        }else if(str=="push_front"){
            int num;
            cin>>num;
            dq.push_front(num);
        }else if(str=="front"){
            if(dq.empty()){
                cout<<-1<<'\n';
            }else{
                cout<<dq.front()<<'\n';
            }
        }else if(str=="back"){
            if(dq.empty()){
                cout<<-1<<'\n';
            }else{
                cout<<dq.back()<<'\n';
            }
        }else if(str=="size"){
            cout<<dq.size()<<'\n';
        }else if(str=="empty"){
            if(dq.empty()){
                cout<<1<<'\n';
            }else{
                cout<<0<<'\n';
            }
        }else if(str=="pop_back"){
            if(dq.empty()){
                cout<<-1<<'\n';
            }else{
                int a = dq.back();
                dq.pop_back();
                cout<<a<<'\n';
            }
            
        }else if(str=="pop_front"){
            if(dq.empty()){
                cout<<-1<<'\n';
            }else{
                int a = dq.front();
                dq.pop_front();
                cout<<a<<'\n';
            }
            
        }
    }
    
    
    return 0;

}