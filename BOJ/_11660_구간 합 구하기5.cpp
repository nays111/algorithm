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
    int arr[1025][1025];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int a;
            cin>>a;
            arr[i+1][j+1]=arr[i][j+1] + arr[i+1][j] + a-arr[i][j]; 
        }
    }
    for(int i=0;i<m;i++){
        int x1,y1,x2,y2;
        cin>>y1>>x1>>y2>>x2;
        cout<<arr[y2][x2] + arr[y1-1][x1-1] - arr[y2][x1-1] - arr[y1-1][x2]<<'\n';
    }
    
    
    
    return 0;
}