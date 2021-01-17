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
bool visited[26][26];
int v[26][26];


int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int totalCount = 0;
int counts = 0;
vector<int> countSet;
void dfs(int y,int x){
    visited[y][x] = true;
    counts++;
    
    for(int i=0;i<4;i++){
        int newY = y+dy[i];
        int newX = x+dx[i];
        if(newX<0 || newY<0 || newX>=n || newY>=n){
            continue;
        }
        if(visited[newY][newX]==false && v[newY][newX]==1){
            // cout<<newY<<" "<<newX<<'\n';
            dfs(newY,newX);
            
        }
    }
}


int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        for(int j=0;j<n;j++){
            v[i][j]=str[j]-'0';
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j]==false && v[i][j]==1){
                counts=0;
                dfs(i,j);
                totalCount++;
                countSet.push_back(counts);
                //cout<<counts;
            }
        }
    }
    sort(countSet.begin(),countSet.end());
    cout<<totalCount<<'\n';
    for(int i=0;i<countSet.size();i++){
        cout<<countSet[i]<<'\n';
    }
    

    return 0;
}