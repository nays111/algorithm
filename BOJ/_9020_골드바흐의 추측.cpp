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
bool isPrime(int n){
    if(n==1){
        return false;
    }else{
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return false; 
            }
        }
    }
    return true;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        vector<pair<int,int>> v;
        int a;
        cin>>a;
        for(int j=2;j<a;j++){
            if(isPrime(j)==true){
                if(isPrime(a-j)==true){
                    v.push_back(make_pair(j,a-j));
                }
            }
        }
        int t;
        int min = abs(v[0].second - v[0].first);
        if(v.size()>2){
            for(int k=0;k<v.size();k++){
                if(abs(v[k].second-v[k].first) < min){
                    min = abs(v[k].second - v[k].first);
                    t=k;
                }
            }
            cout<<v[t].first<<" "<<v[t].second<<'\n';
        }else{
            cout<<v[0].first<<" "<<v[0].second<<'\n';
        }
        
        
    }
    return 0;

}