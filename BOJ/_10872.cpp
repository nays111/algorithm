#include <iostream>
#include <string>
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
int factorial(int num){
    if(num>2){
        num*=factorial(num-1);
    }
    return num;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int N;
    int result = 1;
    cin>>N;
    result = factorial(N);
    cout<<result;
   
    return 0;
}