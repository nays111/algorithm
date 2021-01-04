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
typedef long long ll;
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int temp = n;
    int a = 1;
    
    while(1){
        temp = temp-a;
        a++;
        if(temp<0){
            break;
        }
    }
    vector<int> v;//분자
    //분자구하기
    for(int i=1;i<=a;i++){
        if(i%2!=0){
            for(int j=1;j<i;j++){
                v.push_back(j);
            }
        }else{
            for(int j=i-1;j>0;j--){
                v.push_back(j);
            }
        }
    }
    vector<int> v2;//분모
    //분모 구하기
    for(int i=1;i<=a;i++){
        if(i%2==0){
            for(int j=1;j<i;j++){
                v2.push_back(j);
            }
        }else{
            for(int j=i-1;j>0;j--){
                v2.push_back(j);
            }
        }
    }
    cout<<v[n-1]<<"/"<<v2[n-1];

    return 0;

}