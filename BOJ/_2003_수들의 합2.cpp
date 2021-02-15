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


int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int arr[10001];
    
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        arr[i] = arr[i-1] + a;
    }
    int count = 0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(arr[j]-arr[i-1]==m){
                count++;
                break;
            }
        }
    }
    cout<<count;
    return 0;
}