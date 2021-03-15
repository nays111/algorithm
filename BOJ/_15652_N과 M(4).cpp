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
void func(int cnt,int index){
    if(cnt==m){
        for(int i=0;i<m;i++){
            cout<<arr[i]<<" ";
        }
        cout<<'\n';
    }else{
        for(int i=index;i<=n;i++){
            if(arr[cnt-1]<=i){
                arr[cnt]=i;
                func(cnt+1,index);
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