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
int arr[101][101];
int visit[101][101];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};


void dfs(int y,int x,int target){
    visit[y][x]=true;

    for(int i=0;i<4;i++){
        int nextY = y + dy[i];
        int nextX = x + dx[i];
        if(nextY<0||nextX<0||nextY>=n||nextX>=n){
            continue;
        }
        if(visit[nextY][nextX]==false && arr[nextY][nextX]>target){
            dfs(nextY,nextX,target);
        }
    }

}

void initVisit(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visit[i][j]=false;
        }
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    int maxHeight = 0;
    int minHeight=101;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            if(arr[i][j]>maxHeight){
                maxHeight = arr[i][j];
            }
            if(arr[i][j]<minHeight){
                minHeight = arr[i][j];
            }
        }
    }
    //cout<<maxHeight<<minHeight;
    vector<int> v;

    
    for(int k=0;k<=maxHeight;k++){
        int counts = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(visit[i][j]==false && arr[i][j]>k){
                    dfs(i,j,k);
                    counts++;
                    
                }
            }
        }
        v.push_back(counts);
        initVisit();
    }

    sort(v.begin(),v.end(),greater<>());
    cout<<v[0];
    // for(int i=0;i<v.size();i++){
    //     cout<<i<<":"<<v[i];
    // }
    return 0;
}