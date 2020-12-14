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
    int num = 1000-N;
    int coin[6] = {500,100,50,10,5,1};
    int count=0;
    int sum = 0;
    for(int i=0;i<6;i++){
        if(num>=coin[i]){
            num=num-coin[i];
            count++;
            if(num==0){
                cout<<count;
                break;
            }
            i=0;
        }
    }


    return 0;

}