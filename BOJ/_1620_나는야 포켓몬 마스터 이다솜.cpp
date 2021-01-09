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
    //포켓몬 셋팅
    int n,m;
    cin>>n>>m;
    vector<pair<int,string>> pocketmon;
    map<string,int> pocketmonUsingMap;

    for(int i=1;i<=n;i++){
        string name;
        cin>>name;
        pocketmon.push_back(make_pair(i,name));
        pocketmonUsingMap.insert(make_pair(name,i));
    }
    for(int i=0;i<m;i++){
        string nameOrNum;
        cin>>nameOrNum;
        if(nameOrNum[0]-'\0' >=65 && nameOrNum[0]-'\0'<=90){ //포켓몬 이름으로 찾는 경우
            cout<<pocketmonUsingMap[nameOrNum]<<'\n';
        }else{ //숫자 인덱스로 찾는 경우 => 여긴 문제 없음
            int num = stoi(nameOrNum);
            cout<<pocketmon[num-1].second<<'\n';
        }
        

    }

}