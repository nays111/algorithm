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
int n,m;
int arr[9];
bool visit[9];
void func(int cnt,int index){
    if(cnt==m){
        for(int i=0;i<m;i++){
            cout<<arr[i]<<" ";
        }
        cout<<'\n';
        return;
    }else{
        for(int i=index;i<=n;i++){
            if(visit[i]==false){
                visit[i]=true;
                arr[cnt]=i;
                func(cnt+1,i);
                visit[i]=false;
            }
        }
    }
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    func(0,1);

    
 
    
    return 0;
}