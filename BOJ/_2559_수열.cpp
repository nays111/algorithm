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
    int arr[100001];
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        arr[i] = arr[i-1]+a;
    }
    int answer = -100000000;
    for(int i=0;i<=n-m;i++){
        int sum = arr[i+m]-arr[i];
        answer=max(answer,sum);
    }
    cout<<answer;
    
    return 0;
}