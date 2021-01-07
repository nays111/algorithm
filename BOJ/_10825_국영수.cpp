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
bool comp(const pair<string,vector<int>> &v1,const pair<string,vector<int>> &v2){

    if(v1.second[0]==v2.second[0]){
        if(v1.second[1]==v2.second[1]){
            if(v1.second[2]==v2.second[2]){
                return v1.first < v2.first;
            }
            return v1.second[2] > v2.second[2];
        }

        
        //2) 국어 점수가 같으면 영어 점수가 증가하는 순으로
        return v1.second[1] < v2.second[1];
    }

    //1) 국어 점수가 감소하는 순으로
    return v1.second[0] > v2.second[0];

}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    vector<pair<string,vector<int>>> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string name;
        vector<int> score(3);
        cin>>name;
        for(int i=0;i<3;i++){
            cin>>score[i];
        }
        v.push_back(make_pair(name,score));
    }
    sort(v.begin(),v.end(),comp);
    for(int i=0;i<n;i++){
        cout<<v[i].first<<'\n';
    }
    
    
    
    return 0;

}