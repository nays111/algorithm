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
    //에라스토테네스의 체 이용
    bool isPrime[400000];
    for(int i=2;i<=400000;i++){
        isPrime[i] = true; //일단 다 소수임
    }
    for(int i=2;i<=400000;i++){
        for(int j=i*2;j<=400000;j+=i){
            if(isPrime[j]==false){
                continue;
            }else{
                isPrime[j]=false;//소수아님
            }
        }
    }

    while(1){
        int n;
        cin>>n;
        if(n==0){
            break;
        }
        int count = 0;
        for(int i=n+1;i<=2*n;i++){
            if(isPrime[i]==true){
                //소수라면
                count++;
            }
        }
        cout<<count<<'\n';
    }
    
    return 0;
}