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

int f,s,g,u,d;
//f: 총 층
//s: 강호의 현재 층
//g: 도착해야하는 층
//u: 올라갈수있는층
//d: 내려갈수있는층
bool visit[1000001];
int bfs(){
    queue<pair<int,int>> q;
    q.push(make_pair(s,0));
    visit[s]=true;
    while(!q.empty()){
        int cur = q.front().first;
        int result = q.front().second;
        q.pop();
        if(cur==g){
            return result;
        }
        if(cur+u<=f && visit[cur+u]==false){
            visit[cur+u]=true;
            q.push(make_pair(cur+u,result+1));
        }

        if(cur-d>=1 && visit[cur-d]==false){
            visit[cur-d]=true;
            q.push(make_pair(cur-d,result+1));
        }
    }
    return -1;
}


int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>f>>s>>g>>u>>d;
    int answer = bfs();
    if(answer==-1){
        cout<<"use the stairs";
    }else{
        cout<<answer;
    }   
    return 0;

}