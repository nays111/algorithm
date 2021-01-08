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
    //map을 사용
    map<string,int> m;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string name;
        cin>>name;
        //만약 map안에 이름이 똑같은게 없으면 삽입
        if(m.find(name)==m.end()){
            m.insert(make_pair(name,1));
        }else{
            //똑같은게 있으면 1증가
            m[name]++;
        }
    }
    int max = 0;
    for(auto i=m.begin();i!=m.end();i++){
        if(max < i->second){
            max = i->second;
        }
    }

    for(auto i=m.begin();i!=m.end();i++){
        if(max==i->second){
            cout<<i->first;
            return 0;
        }
    }



    
    return 0;
}