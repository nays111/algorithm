#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    vector<bool> visit(1000001);
    vector<int> arr;
    map<int,int> mp;
    vector<pair<int,int>> v;
    
    
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            string temp;
            for(int j=i;j<s.size();j++){
                
                if(s[j]=='}' || s[j]==',' || visit[j]==true){
                    break;
                }
                visit[j]=true;
                temp = temp + s[j];
            }

            
            if(temp.size()>0){
                int num = stoi(temp);
                arr.push_back(num);

                mp[num]++;
                
            }
        }
    }
    for(auto it = mp.begin(); it != mp.end(); it++){
        v.push_back(make_pair(it->second,it->first));
        
    }
    sort(v.begin(),v.end(),greater<>());
    for(int i=0;i<v.size();i++){
        if(v[i].first>0){
            answer.push_back(v[i].second);
        }
    }
        

    return answer;
}