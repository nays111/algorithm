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
    int N;
    cin>>N;
    int v[10001];
    v[0] = 0;
    v[1] = 1;
    v[2] = 2;
    for(int i=3;i<=N;i++){
        v[i] = (v[i-1])%10007+(v[i-2])%10007;
    }
    cout<<(v[N]%10007);
    return 0;
}