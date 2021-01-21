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
int n;

//int people[101];
bool visit[101];
vector<int> people[101];
int bfs(int start,int end){
    queue<pair<int,int>> q; //first : 사람 인덱스, second : 경로 길이
    q.push(make_pair(start,0));
    visit[start]=true;

    while(!q.empty()){
        int cur = q.front().first;
        int result = q.front().second;
        q.pop();
        
        if(cur==end){
            return result;
        }
        for(int i=0;i<people[cur].size();i++){
            int next = people[cur][i];
            if(visit[next]==false){
                visit[next]=true;
                q.push(make_pair(next,result+1));
            }
        }
    }

    return -1;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    int start,end;
    cin>>start>>end;
    int testCase;
    cin>>testCase;
    for(int i=0;i<testCase;i++){
        int a,b;
        cin>>a>>b;
        people[a].push_back(b);
        people[b].push_back(a);
        
    }
    cout<<bfs(start,end);
    
    
    return 0;

}