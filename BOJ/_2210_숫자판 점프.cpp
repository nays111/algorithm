#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <functional>
using namespace std;

int dx[]= {0,0,-1,1};
int dy[]= {1,-1,0,0};
int arr[5][5];
set<int> s;
//완전탐색
void dfs(int y,int x,int count,int number){
    if(count==6){
        s.insert(number);
        return;
    }

    for(int i=0;i<4;i++){
        int nextY = y+dy[i];
        int nextX = x+dx[i];
        if(nextY<0 || nextX<0 || nextY>=5 || nextX>=5){
            continue;
        }
        dfs(nextY,nextX,count+1,10*number+arr[nextY][nextX]);
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            dfs(i,j,1,arr[i][j]);
        }
    }
    cout<<s.size();

    
    
    return 0;
}