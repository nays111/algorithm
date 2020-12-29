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
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int N,K;
        cin>>N>>K;
        int answer = 0;
        for(int i=0;i<N;i++){
            int a;
            cin>>a;
            answer+=a/K;
        }
        cout<<answer<<'\n';
    }

    return 0;
}