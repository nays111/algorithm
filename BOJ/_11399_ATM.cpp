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
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    int answer = 0;
    for(int i=0;i<v.size();i++){
        int sum = 0;
        for(int j=0;j<=i;j++){
            sum+=v[j];
        }
        answer+=sum;
    }
    cout<<answer;
    
  
    

    return 0;
}