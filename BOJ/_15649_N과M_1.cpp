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
int arr[10];
int check[10];
void dfs(int n,int m,int index){
    if(index==m){
        for(int i=0;i<m;i++){
            cout<<arr[i]<<" ";
        }
        cout<<'\n';
        return;
    }
    for(int i=1;i<=m;i++){
        if(check[i]==0){
            //방문안한경우
            check[i]=1;
            arr[index] = i;
            
            dfs(n,m,index+1);
            check[i]=0;
        }else{
            //방문한경우
            continue;
        }
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);  
    int n,m;
    cin>>n>>m;
    dfs(n,m,0);

    return 0;
}