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
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int H,W,N;
        cin>>H>>W>>N;
        int count=0;
        while(N-H>0){
            N=N-H;
            count++;
        }
        cout<<(N*100)+(count+1)<<endl;
    }
    
    return 0;
}