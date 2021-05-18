#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    int start = 1; //시작 아파트 넘버
    int stations_index = 0;
    
    while(start<=n){
        
        if(start >= stations[stations_index] - w && start <= stations[stations_index] + w){
            //이미 설치된 기지국으로 접근 가능한 아파트
            start = stations[stations_index] + w + 1;
            stations_index++;
            //start 하나 더 증가해야댐
        }else{
            //기지국 설치
            answer++;
            start = start + 2*w + 1;
        }
        
        
    }

    return answer;
}