#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(pair<string,int> a,pair<string,int> b){
    return a.second > b.second;
}

bool compare2(pair<string,pair<int,int>> a,pair<string,pair<int,int>> b){
    if(a.second.first==b.second.first){
        return a.second.second < b.second.second;
    }else{
        return a.second.first > b.second.first;
    }
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,int> mp; //장르이름 + 총 재생횟수
    vector<pair<string,int>> v; //장르이름 + 총 재생횟수
    vector<pair<string,pair<int,int>>> v2;//장르이름+재생횟수+인덱스
    for(int i=0;i<genres.size();i++){
        mp[genres[i]]+=plays[i];
        v2.push_back(make_pair(genres[i],make_pair(plays[i],i)));
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        v.push_back(make_pair(it->first,it->second));
    }
    sort(v.begin(),v.end(),compare);
    sort(v2.begin(),v2.end(),compare2);
    
    for(int i=0;i<v.size();i++){
        int count = 0;
        for(int j=0;j<v2.size();j++){
            if(v[i].first==v2[j].first){
                if(count==2){
                    break;
                }
                answer.push_back(v2[j].second.second);
                count++;
            }
        }
    }    
    return answer;
}