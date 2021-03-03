#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
bool compare(pair<double,int> s,pair<double,int> s2){
    if(s.first==s2.first){
        return s.second<s2.second;//높은게 가장 먼저 나오게
    }else{
        return s.first>s2.first;//낮은게 가장 먼저 나오게
    }
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    map<int,int> mp;
    vector<pair<double,int>> v;
    int arr[501][2]={0,};
    for(int i=0;i<stages.size();i++){
       
        arr[stages[i]][1]++;
    }
    int s = stages.size();
    for(int i=1;i<=N;i++){
        
        double failure=0;
        if(s!=0){
            failure=(double)arr[i][1]/s;
        }
        s=s-arr[i][1];
        v.push_back(make_pair(failure,i));
    }
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<v.size();i++){
        answer.push_back(v[i].second);
    }
    
    return answer;
}