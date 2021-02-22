#include <iostream>
using namespace std;

int GCD(long long a,long long b){
    if(b==0){
        return a;
    }else{
        return GCD(b,a%b);
    }
}


long long solution(int w,int h) {
    long long answer = 1;
    long long W = w;
    long long H = h;
    long long sum = W+H;
    int gcd = GCD(W,H);
    long long multi = W*H;
    answer = multi-sum+gcd;
    return answer;
}