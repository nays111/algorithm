#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    map<int,int> mp;

    for(int i=1;i<=n;i++){
        mp.insert({i,1});
    }
    for(int i=0;i<reserve.size();i++){
        mp[reserve[i]]++;
    }
    for(int i=0;i<lost.size();i++){
        mp[lost[i]]--;
    }

    for(auto it=mp.begin();it!=mp.end();it++){
        if(mp.find(it->first-1)!=mp.end()){
            if(mp[it->first-1]==0 && mp[it->first]==2){
                mp[it->first]--;
                mp[it->first-1]++;
            }
        }else{
            
        }
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        if(mp.find(it->first+1)!=mp.end()){
            if(mp[it->first+1]==0 && mp[it->first]==2){
                mp[it->first]--;
                mp[it->first+1]++;
            }
        }
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        //cout<<it->first<<" "<<it->second<<'\n';
        if(it->second >=1){
            answer++;
        }
    }
    return answer;
}