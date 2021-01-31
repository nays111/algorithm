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

int n;
int number[12];
int plusCount,minusCount,multiplyCount,divideCount;
int maxResult=-1000000000;
int minResult=1000000000;
void dfs(int index,int plus,int minus,int multiply,int divide,int result){
    if(index==n){
        //탈출 -> 마지막 부분까지 연산자 채웠을 때
        maxResult = max(maxResult,result);
        minResult = min(minResult,result);
        return;
    }
    if(plus<plusCount){
        dfs(index+1,plus+1,minus,multiply,divide,result+number[index]);
    }
    if(minus<minusCount){
        dfs(index+1,plus,minus+1,multiply,divide,result-number[index]);
    }
    if(multiply<multiplyCount){
        dfs(index+1,plus,minus,multiply+1,divide,result*number[index]);
    }
    if(divide<divideCount){
        dfs(index+1,plus,minus,multiply,divide+1,result/number[index]);
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>number[i];
    }
    cin>>plusCount>>minusCount>>multiplyCount>>divideCount;
    dfs(1,0,0,0,0,number[0]);
    cout<<maxResult<<'\n'<<minResult;
    return 0;
}