#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(),people.end());
    int front = people[0];
    int frontIndex = 0;
    while(people.size()>frontIndex){
        int back = people.back();
        if(people[frontIndex]+back>limit){
            people.pop_back();
            answer++;
        }else{
            people.pop_back();
            frontIndex++;
            answer++;
        }
    }
    return answer;
}