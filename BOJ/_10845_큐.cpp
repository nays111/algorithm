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
    queue<int> q;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        if(str=="push"){
            int n;
            cin>>n;
            q.push(n);
        }
        if(str=="pop"){
            if(!q.empty()){
                cout<<q.front()<<'\n';
                q.pop();
            }else{
                cout<<-1<<'\n';
            }
        }
        if(str=="front"){
            if(!q.empty()){
                cout<<q.front()<<'\n';
            }else{
                cout<<-1<<'\n';
            }
        }if(str=="back"){
            if(!q.empty()){
                cout<<q.back()<<'\n';
            }else{
                cout<<-1<<'\n';
            }
        }
        if(str=="size"){
            cout<<q.size()<<'\n';
        }
        if(str=="empty"){
            if(q.empty()){
                cout<<1<<'\n';
            }else{
                cout<<0<<'\n';
            }
        }
    }

    

    return 0;
}