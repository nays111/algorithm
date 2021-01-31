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

bool compare(const pair<int,int> &v1,const pair<int,int> &v2){
    if(v1.second < v2.second){
        return true;
    }else if(v1.second==v2.second){
        if(v1.first<v2.first){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int start,end;
        cin>>start>>end;
        v.push_back(make_pair(start,end));
    }
    sort(v.begin(),v.end(),compare);
    int endTime = 0;
    int counts = 0;
    for(int i=0;i<v.size();i++){
        if(endTime<=v[i].first){
            endTime = v[i].second;
            counts++;
        }
    }
    cout<<counts;

    

 
    return 0;

}