#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map <string,int> m;
    int len = clothes.size();
    for(int i=0;i<len;i++){
        string str = clothes[i][1]; //headgear, eyewear, ~~~
        m[str]++;
    }
    for(auto i=m.begin();i!=m.end();i++){
        answer*=(i->second)+1;
    }
    return answer-1;
}