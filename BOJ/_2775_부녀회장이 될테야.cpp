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

int arr[15][15];

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);  
    int t;
    cin>>t;
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            arr[0][j] = j;
            arr[i][1] = 1;
            arr[i][0] = 0;
        }
    }
    for(int i=1;i<15;i++){
        for(int j=1;j<15;j++){
            arr[i][j] = arr[i-1][j]+arr[i][j-1];
        }
    }
    for(int i=0;i<t;i++){
        int k,n;
        cin>>k>>n;
        cout<<arr[k][n]<<'\n';

    }
    return 0;
}