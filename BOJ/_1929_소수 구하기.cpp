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

bool isPrime(int n){
    if(n==0 || n==1){
        return false;
    }else{
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return false;
            }
        }
    }
    return true;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);  
    int m,n;
    cin>>m>>n;
    for(int i=m;i<=n;i++){
        if(isPrime(i)==true){
            cout<<i<<'\n';
        }
    }
    return 0;
}