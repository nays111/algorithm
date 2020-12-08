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
int fibo(int n){
    
    int x=1;
    if(n>=2){
        x=fibo(n-1)+fibo(n-2);
    }else if(n==1){
        x=1;
    }else if(n==0){
        x=0;
    }
    return x;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
    int answer;
    cin>>n;
    answer = fibo(n);
    cout<<answer;


    return 0;

}