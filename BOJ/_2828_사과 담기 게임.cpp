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
    int N,M,J;
    cin>>N>>M;
    cin>>J;
    int left = 0;
    int right = M-1;
    int distance = 0;
    for(int i=0;i<J;i++){
        int b;
        cin>>b;
        int a=b-1;
        if(a>right){
            distance += a-right;
            right = a;
            left = a-M+1;
        }else if(a<left){
            distance +=left-a;
            left = a;
            right = a+M-1;
        }
    }
    cout<<distance;
    return 0;
}