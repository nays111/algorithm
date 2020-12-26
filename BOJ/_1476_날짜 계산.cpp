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
    int e,s,m;
    cin>>e>>s>>m;
    int answer=1;
    int i=1;
    int j=1;
    int k=1;
    while(1){
        if(i==e && j==s && k==m){
            break;
        }
        i++;
        j++;
        k++;
        if(i>15){
            i=1;
        }
        if(j>28){
            j=1;
        }
        if(k>19){
            k=1;
        }
        answer++;
        
    }
    cout<<answer;
    return 0;
}