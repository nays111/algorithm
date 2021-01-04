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
    vector<int> v(10001);
    for(int i=0;i<n;i++){
        int in;
        cin>>in;
        v[in]++;
    }
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i];j++){
            cout<<i<<'\n';
        }
        
    }

    return 0;
}