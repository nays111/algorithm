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
    int P1,P2,P3,X1,X2,X3;
    cin>>P1>>P2>>P3>>X1>>X2>>X3;
    long long N=0;
    long long gcd = __gcd(__gcd(P1,P2),P3);
    long long max = gcd* (P1/gcd) * (P2/gcd) * (P3/gcd);
    while(N<max){
        if(N%P1==X1 && N%P2==X2 && N%P3==X3){
            cout<<N;
            return 0;
        }
        N++;
    }
    cout<<-1;
    return 0;
}