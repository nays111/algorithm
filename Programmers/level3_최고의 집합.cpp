#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;

    if(n>s){
        answer.push_back(-1);
        return answer;
    }
    
    int p = s/n;
    int r = s%n;
    
    if(r!=0){ //나누어 떨어지지않는 경우
        //나머지를 1씩 나눠준다.
        int np = p+1;
        for(int i=0;i<r;i++){
            answer.push_back(np);
        }
        for(int i=0;i<n-r;i++){
            answer.push_back(p);
        }
    }else{ //나누어 떨어지는 경우
        for(int i=0;i<n;i++){ //n개 만큼 p를 넣으면 됨
            answer.push_back(p);
        }
    }
    sort(answer.begin(),answer.end());

    return answer;
}