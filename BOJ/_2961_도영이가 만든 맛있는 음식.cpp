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
vector<pair<int,int>> v;
int answer = 987654321;
void recur(int cnt,int s,int d){ //s : 신, d : 단

    if(cnt==n){
        if(s>1 && d>0){ //최소 한개는 사용해야하니깐
            answer = min(answer,abs(s-d));
        }
        return;
    }
    recur(cnt+1,s*v[cnt].first,d+v[cnt].second); //선택 한 경우
    recur(cnt+1,s,d);//선택 안 한 경우
}


int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        int s,d;
        cin>>s>>d;
        v.push_back(make_pair(s,d));
    }
    recur(0,1,0);
    cout<<answer;
    
    

    return 0;

}


