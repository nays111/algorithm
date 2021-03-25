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
#define INF 987654321
using namespace std;



int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    long long start,target;
    cin>>start>>target;
    queue<pair<long long,long long>> q;
    map<long long,bool> mp;
    q.push({start,0});
    mp[start]=true;
    while(!q.empty()){
        long long cur = q.front().first;
        long long cnt = q.front().second;
        q.pop();
        if(cur==target){
            cout<<cnt+1;
            return 0;
        }
        long long next1 = 10*cur+1;
        long long next2 = cur*2;
        if(next2<=target && mp.find(next2)==mp.end()){
            q.push({next2,cnt+1});
            mp[next2]=true;
            
        }
        if(next1<=target && mp.find(next1)==mp.end()){
            q.push({next1,cnt+1});
            mp[next1]=true;
        }
        
    }
    cout<<-1;
    return 0;
}