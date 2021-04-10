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

typedef long long ll;



int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n,m;
    cin>>n>>m;
    vector<ll> v;
    ll right;
    for(int i=0;i<m;i++){
        ll a;
        cin>>a;
        right+=a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    ll left = 1;
    int answer = 0;
    while(left<=right){
        ll mid = (left+right)/2;
        ll cnt = 0;
        for(int i=0;i<v.size();i++){
            if(v[i]%mid==0){
                cnt+=(v[i]/mid);
            }else{
                cnt+=(v[i]/mid)+1;
            }
        }
        if(cnt<=n){
            right = mid - 1;
            answer = mid;
        }else{
            left = mid + 1;
        }
        
    }
    cout<<answer;
    

    return 0;
}