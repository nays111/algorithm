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
    vector<pair<int,int>> v(8);
    vector<int> index;

    for(int i=0;i<8;i++){
        cin>>v[i].first;
        v[i].second = i+1;
    }

    sort(v.begin(),v.end(),greater<>());
    int sum = 0;
    for(int i=0;i<5;i++){
        sum = sum + v[i].first;
        index.push_back(v[i].second);
    }
    cout<<sum<<'\n';
    sort(index.begin(),index.end());
    for(int i=0;i<index.size();i++){
        cout<<index[i]<<" ";
    }





    return 0;
    
}