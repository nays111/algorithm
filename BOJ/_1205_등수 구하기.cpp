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
    int n,score,limit;
    cin>>n>>score>>limit;
    vector<int> v;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    int rank = 1;
    //꽉차있다면 점수가
    if(n==limit && score<=v[n-1]){
        cout<<-1;
        return 0;
    }else{
        for(int i=0;i<v.size();i++){
            if(score<v[i]){
                rank = rank + 1;
            }
        }
    }
    cout<<rank;





    return 0;
    
}