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
vector<int> v;
int sum;
int answer = 0;
void calc(int index,int tempSum){
    cout<<"("<<index<<","<<tempSum<<")"<<'\n';
    if(index==v.size()){
        if(tempSum==sum){
            answer++;   
        }
        return;
    }
    
    calc(index+1,v[index]+tempSum);
    calc(index+1,tempSum);
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
    
    cin>>n>>sum;
    
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    calc(0,0);
    //합이 0일때는 아무것도 고르지 않은 경우가 있으므로 1빼준다.
    if(sum==0){
        cout<<answer-1;
    }else{
        cout<<answer;
    }
    
    return 0;

}