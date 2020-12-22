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
    int N,M;
    cin>>N>>M;
    int basket[100]={0,};
    int a=0;
    int b=0;
    int temp = 0;
    for(int i = 0; i <N; i++){
		basket[i] = i + 1;
	}
    for(int i=0;i<M;i++){
        
        cin>>a>>b;
        temp = basket[a-1];
        basket[a-1] = basket[b-1];
        basket[b-1]=temp;
    }
    for(int i=0;i<N;i++){
        cout<<basket[i]<<" ";
    }
    return 0;
}