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


int n,k;
bool visit[100001];

void bfs(){
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    //시간 적게 걸리는 게 우선순위가 높음
    visit[n]=true;
    pq.push(make_pair(0,n));

    while(!pq.empty()){
        int time = pq.top().first;
        int cur = pq.top().second;
        visit[cur]=true;
        
        pq.pop();
        if(cur==k){
            cout<<time;
            return;
        }
         
        if(cur-1>=0 && visit[cur-1]==false){
            pq.push(make_pair(time+1,cur-1));
            //visit[cur-1]=true;
        }
        if(cur+1<100001 && visit[cur+1]==false){
            pq.push(make_pair(time+1,cur+1));
            //visit[cur+1]=true;
        }
        if(cur*2<100001 && visit[cur*2]==false){
            pq.push(make_pair(time,cur*2));
            //visit[cur*2]=true;
        }
       
    }
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin>>n>>k;
    bfs();
    return 0;

}


