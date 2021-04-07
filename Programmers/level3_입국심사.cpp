#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(),times.end());
    long long right = (long long)times[times.size()-1]*n;
    long long left = 1;
    while(left<=right){
        long long mid = (right+left)/2;
        long long cnt = 0;
        for(int i=0;i<times.size();i++){
            cnt+= (long long)(mid/times[i]);
        }
        
        if(cnt<n){
            left = mid + 1;
        }else{
            
            answer = mid;
            
            right = mid - 1;
        }

    }
    return answer;
}