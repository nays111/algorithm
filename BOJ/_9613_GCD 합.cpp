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
int GCD(int a,int b){
    if(b==0){
        return a; 
    }else{
        return GCD(b,a%b);
    }
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int arr[n];
        long long sum = 0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                sum+=GCD(arr[i],arr[j]);
            }
        }
        cout<<sum<<'\n';
    }
    return 0;
}