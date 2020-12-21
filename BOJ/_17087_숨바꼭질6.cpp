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
int GCD(int a,int b){
    if(b==0){
        return a; 
    }else{
        return GCD(b,a%b);
    }
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int N;
    int A;
    cin>>N>>A;
    int arr[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    int distance[N];
    for(int i=0;i<N;i++){
        distance[i] = abs(arr[i] - A);
    }
    int temp = distance[0];
    for(int i=1;i<N;i++){
        temp = GCD(distance[i],temp);
    }
    cout<<temp;
    return 0;
}