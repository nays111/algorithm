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
vector<pair<int,int>> v;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int a,b,N;
        int answer=1;
        cin>>N;
        v.clear();
        for(int i=0;i<N;i++){
            cin>>a>>b;
            v.push_back(make_pair(a,b));
        }
        sort(v.begin(),v.end());
        int min = v[0].second;//면접순위에 대해서만 판단 시작
        for(int i=1;i<N;i++){
            if(v[i].second<min){
                answer++;
                min = v[i].second;
            }
        }
        cout<<answer<<endl;
        answer = 1;

    }
    return 0;
}