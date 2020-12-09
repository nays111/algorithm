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
    cin>>n;
    int vec[n];
    
    vec[0]=1;
    vec[1]=2;
    for(int i=2;i<=n;i++){
        vec[i] = vec[i-1]+vec[i-2];
        vec[i]=vec[i]%15746;
    }
    cout<<vec[n-1];

    return 0;
}