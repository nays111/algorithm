#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

bool compare(pair<int,int> p1,pair<int,int> p2){
    int minus1 = p1.second - p1.first;
    int minus2 = p2.second - p2.first;
    if(minus1==minus2){
        return p1.first < p2.first;
    }else{
        return minus1 < minus2;
    }
}

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    
    map<string,int> mp;
    set<string> s;
    
    for(int i=0;i<gems.size();i++){
        s.insert(gems[i]);
    }
    
    
    int start = 0;
    int end = 0;
    vector<pair<int,int>> v;
    
    while(1){
        if(s.size()==mp.size()){
            v.push_back({start,end});
            
            if(mp[gems[start]]==start){
                mp.erase(gems[start]);
            }
            
            start++;
        }else if(end==gems.size()){
            break;
        }else{
            mp[gems[end]]=end;
            end++;
        }
    }

    sort(v.begin(),v.end(),compare);

    answer.push_back(v[0].first+1);
    answer.push_back(v[0].second);
    return answer;
}