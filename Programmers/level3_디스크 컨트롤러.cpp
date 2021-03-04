#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

bool compare(vector<int> v1,vector<int> v2){
    return v1[1]<v2[1];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(),jobs.end(),compare);//소요시간으로 정렬
    int start = 0;
    int totalSoyo = 0;
    int size = jobs.size();
    while(!jobs.empty()){
        for(int i=0;i<jobs.size();i++){
            if(jobs[i][0] <=start){
                start = start + jobs[i][1];
                int soyo = start - jobs[i][0];
                totalSoyo += soyo;
                jobs.erase(jobs.begin()+i); //일 했으니깐 빼
                break;
            }
            if(i==jobs.size()-1){
                start ++;
                cout<<start;
            }
        }
    }
    answer = totalSoyo/size;
    return answer;
}