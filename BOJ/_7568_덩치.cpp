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
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int height,weight;
        cin>>weight>>height;
        v.push_back(make_pair(weight,height));
    }
    vector<int> rank(n);
    for(int i=0;i<n;i++){ //0vs1, 0vs2, 0vs3, 0vs4, 1vs2, 1vs3, 1vs4, 2vs3, 2vs4, 3vs4
        for(int j=0;j<n;j++){
            if(v[i].first < v[j].first && v[i].second < v[j].second){
                rank[i]++;
            }
        }
    }

    for(int i=0;i<rank.size();i++){
        cout<<rank[i]+1;
    }
    return 0;
}