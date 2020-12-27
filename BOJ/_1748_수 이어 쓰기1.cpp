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
    int n;
    cin>>n;
    int c=n;
    int len = 0;
    int answer =0;
    while(n>0){
        n=n/10;
        len++;
    }
    for(int i=1;i<len;i++){
        answer= answer + (pow(10,i)-pow(10,i-1))*i;
    }
    answer= answer + (c-pow(10,len-1)+1)*len;
    cout<<answer;
    

    return 0;
}