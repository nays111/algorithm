#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int len = citations.size();
    sort(citations.begin(),citations.end(),greater<>());
    
    for(int i=0;i<len;i++){
        if(citations[i]>i){
            answer++;
        }
    }
    
    return answer;
}