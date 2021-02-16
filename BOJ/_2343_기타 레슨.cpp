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

int n,m;
int arr[100001];
bool func(int mid){
    int count = 1;
    int sum = 0;
    for(int i=0;i<n;i++){
        if(arr[i]>mid){
            return false;
        }
        sum+=arr[i];
        if(sum>mid){
            //일단 이것만큼 블루레이에 넣어본다.
            sum = arr[i];
            count++;
        }

    }
    if(count<=m){
        return true;
    }else{
        return false;
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    int left,right;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        right = right + arr[i];
    }
    int answer = 0;
    while(left<=right){
        int mid = (left+right)/2;

        if(func(mid)==true){
            right = mid-1;
            answer = mid;
        }else{
            left  = mid +1;
        }
    }
    cout<<answer;

    
    return 0;
}