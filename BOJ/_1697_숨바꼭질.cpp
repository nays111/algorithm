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

#define MAX 100001

bool visit[MAX];
int bfs(int start,int target){
    queue<pair<int,int>> q;
    q.push(make_pair(start,0));
    visit[start]=true;
    while(!q.empty()){
        int cur = q.front().first;
        int result = q.front().second;
        q.pop();
        if(cur==target){
            return result;
        }
        if(cur-1>=0 && visit[cur-1]==false){
            q.push(make_pair(cur-1,result+1));
            visit[cur-1]=true;
        }
        if(cur+1<MAX && visit[cur+1]==false){
            q.push(make_pair(cur+1,result+1));
            visit[cur+1]=true;
        }
        if(cur*2<MAX && visit[cur*2]==false){
            q.push(make_pair(cur*2,result+1));
            visit[cur*2]=true;
        }
    }
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    cout<<bfs(n,k);
    return 0;

}