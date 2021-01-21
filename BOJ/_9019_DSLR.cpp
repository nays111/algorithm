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
bool visit[10001];

void bfs(int start,int target){
    memset(visit,false,sizeof(visit));
    queue<pair<int,string>> q;
    q.push(make_pair(start,""));
    visit[start]=true;
    while(!q.empty()){
        
        int cur = q.front().first;
        string result = q.front().second;
        q.pop();
        if(cur==target){
            cout<<result<<'\n';
            break;
        }
        //D
        int next = cur*2;
        if(next>9999){
            next=next%10000;
        }
        if(visit[next]==false){
            visit[next]=true;
            q.push(make_pair(next,result+"D"));
        }
        //S
        next=cur-1;
        if(next<0){
            next=9999;
        }
        if(visit[next]==false){
            visit[next]=true;
            q.push(make_pair(next,result+"S"));
        }
        //L
        next = (cur%1000)*10 + cur/1000;
        if(visit[next]==false){
            visit[next]=true;
            q.push(make_pair(next,result+"L"));
        }
        //R
        next = (cur%10)*1000 + cur/10;
        if(visit[next]==false){
            visit[next] =true;
            q.push(make_pair(next,result+"R"));

        }
    }
    
}



int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        
        int a,b;
        cin>>a>>b;
        bfs(a,b);
        
    }
    

}
