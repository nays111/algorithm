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
vector<int> vec1;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int N,M;
    cin>>N;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        vec1.push_back(a);
    }
    sort(vec1.begin(),vec1.end());
    cin>>M;
    for(int i=0;i<M;i++){
        int a;
        cin>>a;
        cout<<upper_bound(vec1.begin(),vec1.end(),a)-lower_bound(vec1.begin(),vec1.end(),a);
    }
    return 0;
}