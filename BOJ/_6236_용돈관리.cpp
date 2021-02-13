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
vector<int> money;
int total;
//인출하는 양이 하루 쓸 양보다 적으면 안됨
bool func(int mid){
    int count = 1;
    int nowMoney  = mid;//mid ->하루 한도
    for(int i=0;i<n;i++){
        if(money[i]>mid){ //인출하는 양이 하루 쓸양보다 적으면 x
            return false;
        }
        //nowMoney : 남은돈
        if(money[i]>nowMoney){ //모자라게된경우
        
            nowMoney = mid;//남은돈을 다시 넣음
            count++;
        }
        nowMoney-=money[i]; 
    }
    if(count>m){
        return false;
    }else{
        return true;
    }
}


int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        money.push_back(a);
        total = total + a;
    }
    int left = 1;//무조건 돈은 최소 1원 써야함 하루에
    int right = total;
    int answer = total;
    while(left<=right){
        int mid = (left+right)/2;

        if(func(mid)==true){
            right = mid -1;
            answer = min(answer,mid);
        }else{
            left = mid+1; //false니깐 더 한도를 올린다
        }
    }
    cout<<answer;
    
    return 0;
}