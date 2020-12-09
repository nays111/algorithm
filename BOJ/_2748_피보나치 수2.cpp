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
long long arr[91];
long long fibo(int n){
    arr[0] = 0;
    arr[1] = 1;
    for(int i=0;i<n;i++){
        arr[i+2] = arr[i+1]+arr[i];
    }
    return arr[n];
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    cout<<fibo(n);
    return 0;

}