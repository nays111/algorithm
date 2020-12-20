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
    
    int N,K;
    cin>>N>>K;
    vector<int> v(N+1);
    for(int i=1;i<=N;i++){
        v[i]=i;
    }
    bool isDeleted[N+1]={false,};
    int count = 0;
    for(int i=2;i<=N;i++){
        for(int j=i;j<=N;j+=i){
            if(isDeleted[j]==false){
                isDeleted[j]=true;
                count++;
                if(count == K){
                    cout<<v[j];
                }
            }
        }
    }
    return 0;
}