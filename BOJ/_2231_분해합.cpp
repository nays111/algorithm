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
    int answer;
    bool flag = false;
    cin>>N;
    for(int i=1;i<N;i++){
        int sum = i;
        int temp = i;
        
        while(temp>0){
            sum+=temp%10;
            temp = temp/10;
        }
        if(sum==N){
            cout<<i;
            return 0;
        }
    }
    cout<<0;
    return 0;
}