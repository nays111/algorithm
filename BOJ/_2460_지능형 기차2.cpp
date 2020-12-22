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
    int out,in;
    int people=0;
    int maxPeople = 0;
    for(int i=0;i<10;i++){
        cin>>out>>in;
        people+=in-out;
        if(maxPeople<people){
            maxPeople = people;
        }
        
    }
    
    cout<<maxPeople;
    return 0;
}