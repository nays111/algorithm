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
    vector<int> v;
    vector<int> v2;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    for(int i=0;i<n;i++){
        int b;
        cin>>b;
        v2.push_back(b);
    }
    sort(v.begin(),v.end(),greater<>());
    sort(v2.begin(),v2.end());
    int sum = 0;
    for(int i=0;i<n;i++){
        sum=sum+v[i]*v2[i];
    }
    cout<<sum;
    
    
    return 0;
}