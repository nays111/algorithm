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
    int arr[N];
    int count =0;
    for(int i=0;i<N;i++){
        cin>>arr[i];
        int countPrime=0;
        for(int j=1;j<=arr[i];j++){
            if(arr[i]%j==0){
                countPrime++;
            }
        }
        if(countPrime==2){
            count++;
        }
    }
    cout<<count;
    return 0;
}