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

int arr[101][101]={0};
int visit[101]={0};
int computerNum;
int lineNum;
int answer = 0;
void dfs(int n){
    answer++;
    visit[n]=1;
    for(int i=1;i<=computerNum;i++){
        if(arr[n][i]==1 && !visit[i]){
            dfs(i);
        }
    }
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int x,y;
    cin>>computerNum>>lineNum;
    for(int i=0;i<lineNum;i++){
        cin>>x>>y;
        arr[x][y]=arr[y][x]=1;
    }
    dfs(1);
    cout<<answer-1;

    return 0;
}