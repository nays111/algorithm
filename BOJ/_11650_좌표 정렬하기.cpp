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
#include <utility>
using namespace std;
bool compare(pair<int,int>&arr1,pair<int,int>&arr2){
    if(arr1.first < arr2.first){
        return true;
    }else if(arr1.first == arr2.first){
        if(arr1.second<arr2.second){
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
    int N;
    cin>>N;
    vector<pair<int, int>> vec(N);
    for(int i=0;i<N;i++){
        cin>>vec[i].first>>vec[i].second;
    }
    sort(vec.begin(),vec.end(),compare);
    for(int i=0;i<N;i++){
        cout<<vec[i].first<<" "<<vec[i].second<<endl;
    }
    
    return 0;
}