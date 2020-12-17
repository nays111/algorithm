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
    vector<int> v;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end(),greater<>());
    int sum = 0;
    for(int i=0;i<N;i++){
        if(i%3!=2){
            sum+=v[i];
        }
    }
    cout<<sum;
    

    return 0;

}