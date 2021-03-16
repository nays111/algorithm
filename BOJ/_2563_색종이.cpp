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
    int n;
    int arr[101][101]={0,};
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        for(int j=a;j<a+10;j++){
            for(int l=100-b;l>100-b-10;l--){
                arr[l][j]=1;
            }
        }
    }
    int cnt = 0;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            //cout<<arr[i][j];
            if(arr[i][j]==1){
                cnt++;
            }
        }
        //cout<<'\n';
    }
    cout<<cnt;
    
    return 0;
}