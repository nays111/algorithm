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
    stack<pair<int,int>> left;
    stack<pair<int,int>> right;
    vector<pair<int,int>> v;
    int maxHeight=0;
    int indexOfMaxHeight=0;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        if(maxHeight<y){
            maxHeight = y;
            indexOfMaxHeight = x;
        }
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(),v.end());
    int index;
    for(int i=0;i<v.size();i++){
        if(v[i].second==maxHeight && v[i].first==indexOfMaxHeight){
            index = i;
        }
    }
    
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i].first<<" "<<v[i].second<<'\n';

    // }
    // cout<<indexOfMaxHeight<<": "<<maxHeight<<'\n';
    // cout<<'\n';
    for(int i=0;i<index;i++){
        if(right.empty()){
            right.push(make_pair(v[i].first,v[i].second));
        }else{
            if(right.top().second < v[i].second){
                right.push(make_pair(v[i].first,v[i].second));
            }
        }
    }
    // while(!right.empty()){
    //     cout<<right.top().first<<" "<<right.top().second<<'\n';
    //     right.pop();
    // }

    for(int i=v.size()-1;i>index;i--){
        if(left.empty()){
            left.push(make_pair(v[i].first,v[i].second));
        }else{
            if(left.top().second < v[i].second){
                left.push(make_pair(v[i].first,v[i].second));
            }
        }
    }
    // cout<<'\n';
    // while(!left.empty()){
    //     cout<<left.top().first<<" "<<left.top().second<<'\n';
    //     left.pop();
    // }
    int answer = 1*maxHeight;
    int temp = indexOfMaxHeight;
    while(!right.empty()){
        //cout<<answer<<'\n';
        answer = answer + right.top().second*(temp-right.top().first);
        temp=right.top().first;
        right.pop();
    }
    int temp2 = indexOfMaxHeight + 1;
    while(!left.empty()){
        //cout<<"answer:"<<answer<<"left.top():"<<left.top().first<<" "<<left.top().second;
        answer = answer + left.top().second*(left.top().first+1-temp2);
        temp2 = left.top().first+1;
        left.pop();
    }
    cout<<answer;



    return 0;

}