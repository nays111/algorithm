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


int n,m,k,x;
vector<int> v[300001];
bool visit[300001];
vector<int> answer;
void bfs(){
    //priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    //first : 시간, second : 도시번호
    queue<pair<int,int>> q;
    
    //pq.push(make_pair(0,x));
    q.push(make_pair(x,0));
    visit[x] = true;
    while(!q.empty()){
        int curCity = q.front().first;
        int curDist = q.front().second;
        //cout<<curCity<<" "<<curDist<<'\n';
        
        q.pop();
        if(curDist==k){
            
            answer.push_back(curCity);
        }
        for(int i=0;i<v[curCity].size();i++){
            int nextCity = v[curCity][i];
            //cout<<nextCity<<'\n';
            if(visit[nextCity]==false){
                visit[nextCity]=true;
                q.push(make_pair(nextCity,curDist+1));
            }
        }

    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin>>n>>m>>k>>x;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
    }
    bfs();
    if(answer.empty()){
        cout<<-1;
    }else{
        sort(answer.begin(),answer.end());
        for(int i=0;i<answer.size();i++){
            cout<<answer[i]<<'\n';
        }
    }
    return 0;

}


