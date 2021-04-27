#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    map<string,string> mp;
    
    int n = enroll.size();
    
    map<string,long long> money;
    
    
    for(int i=0;i<n;i++){
        if(referral[i] == "-"){
            mp[enroll[i]] = "center";
            money["center"] = 0;
        }else{
            mp[enroll[i]] = referral[i];
            money[enroll[i]] = 0;
        }
        
    }
    
    for(int i=0;i<seller.size();i++){
        long long n = amount[i] * 100;
        
        string person = seller[i];
        
        money[person]+=n;
        while(1){
            if(mp.find(person)!=mp.end()){
                if(n/10 >=1){
                    money[person] -= n/10;
                    money[mp[person]] += n/10;
                    n = n/10;
                }
                person = mp[person];
            }
            if(person=="center"){
                break;
            }
        }
    }
    
    for(int i=0;i<enroll.size();i++){
        answer.push_back(money[enroll[i]]);
    }

    return answer;
}