#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    int sum = 0;
    int start = 1;
    for(int i=1;i<=n;i++){
        int sum=0;
        int start = i;
        while(sum<n){
            sum = sum + start;
            start++;
            if(sum==n){
                answer++;
                break;
            }
        }
    }
    return answer;
}