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
    for(int i=1;i<=n;i++){
        v.push_back(i);
    }
    do{
        for(int i=0;i<n;i++){
            cout<<v[i]<<" ";
        }
        cout<<'\n';
    }while(next_permutation(v.begin(),v.end()));
    return 0;
}