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
    long long N,M;
    cin>>N>>M;
    //vector <long long> tree;
    long long tree[N];
    long long max = 0;
    long long min = 1000000001;
    for(long long i=0;i<N;i++){
        //int a;
        //cin>>a;
        //tree.push_back(a);
        cin>>tree[i];
        if(tree[i]>max){
            max = tree[i];
        }
        if(tree[i]<min){
            min = tree[i];
        }
    }
    //나무를 기준으로 하면 안됨
    long long left = 0;
    long long right = max;
    long long answer = 0;
    while(left<=right){
        long long mid = (left+right)/2;
        long long sum = 0;
        for(long long i=0;i<N;i++){
            if(mid<tree[i]){
                sum+=tree[i]-mid;
            }
        }
        if(sum<M){ // 더 잘라야댐
            right = mid-1;
        }else{
            if(answer<mid){
                answer = mid;
            }
            left = mid+1;
        }
    }
    cout<<answer;
    return 0;
}