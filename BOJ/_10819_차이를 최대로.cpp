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
int n;
vector<int> v;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    int max = 0;
    do{
        int sum = 0;
        for(int i=0;i<v.size()-1;i++){
            int minus = abs(v[i]-v[i+1]);
            sum+=minus;
        }
        if(sum>max){
            max = sum;
        }
    }while(next_permutation(v.begin(),v.end()));
    cout<<max;
    return 0;
}