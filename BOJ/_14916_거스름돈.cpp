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
    int answer=0;
    int arr[5]={1,3,2,4,3};
    if(N==1 || N==3){
        cout<<-1;
    }else if(N==2){
        cout<<1;
    }else if(N==4){
        cout<<2;
    }else{
        int n = N%5;
        int c = (N/5)-1;
        answer = arr[n]+c;
        cout<<answer;
    }



    return 0;

}