#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> dq;
    if(cacheSize==0){
        return cities.size()*5;
    }
    
    
    for(int i=0;i<cities.size();i++){
        string city = cities[i];
        transform(city.begin(),city.end(),city.begin(),::toupper);
        //cout<<city<<" ";
        bool hit = false;
        int index=0;
        for(int j=0;j<dq.size();j++){
            if(dq[j]==city){
                hit = true;
                index = j;
                break;
            }
        }
        if(hit==true){//hit인 경우
            dq.erase(dq.begin()+index);//기존걸 제거해야함
            dq.push_back(city);
            answer+=1;
        }else if(hit==false){ //miss인경우
            if(dq.size()==cacheSize){ //꽉차서 LRU 로 교체해야함
                dq.pop_front();//가장 오래된거를 빼고
                dq.push_back(city);
                answer+=5;
            }else{
                dq.push_back(city);
                answer+=5;
            }
        }
    }
    return answer;
}