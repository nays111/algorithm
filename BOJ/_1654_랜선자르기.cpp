#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <stack>
#include <queue>
#include <map>
#include <functional>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int K;
    long long N;
    cin>>K>>N;
    vector <long long> v;
    long long max = 0;
    
    for(int i=0;i<K;i++){
        int a;
        cin>>a;
        v.push_back(a);
        if(a>max){
            max = a;
        }
    }
    long long left = 1;
    long long right = max;
    long long answer = 0;
    while(left<=right){
        long long mid = (left+right)/2;
        int result = 0;
        for(int i=0;i<K;i++){
            result += v[i]/mid;
        }
        
        if(result<N){
            right = mid-1;
        }else{
            left = mid+1;
            answer = mid;           
        }
    }
    cout<<answer;
    
    return 0;
}