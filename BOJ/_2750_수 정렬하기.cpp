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
    long long n;
    cin>>n;
    vector<long long> v;
    for(int i=0;i<n;i++){
        long long a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    for(int  i=0;i<v.size();i++){
        cout<<v[i]<<'\n';
    }
    
    return 0;

}