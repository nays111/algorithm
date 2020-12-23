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
vector<int> v[2000]; //인접리스트
bool a[2000][2000];//인접행렬
vector<pair<int,int>> v2;//간선리스트
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int N,M;
    cin>>N>>M;
    
    for(int i=0;i<M;i++){
        int from,to;
        cin>>from>>to;
        v2.push_back({from,to});//v2[0] :{1,2} 1이랑 2랑 연결되어있다는 뜻
        v2.push_back({to,from});//v2[0] :{2,1} 위에게 연결되어있으면 아래것도 연결
        a[from][to]=true;
        a[to][from] = true;
        v[from].push_back(to);
        v[to].push_back(from);
    }
    M*=2; //양방향이기 때문에 추가
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            //A랑 B랑 연결됬다고 나타내는것 -> 간선리스트
            int A = v2[i].first;
            int B = v2[i].second;
            //C랑 D랑 연결됬다고 나타내는 것 -> 간선리스트
            int C = v2[j].first;
            int D = v2[j].second;
            if (A == B || A == C || A == D || B == C || B == D || C == D) {
                continue;
            }
            //B랑 C랑 연결되었는지 확인하는 것 -> 인접행렬
            if(a[B][C]==false){
                continue; //인접행렬에 false라 되있으면 연결안되있는 것
            }
            //마지막으로 D랑 E가 연결되어있는지 확인해야함 -> 인접리스트
            for(int E : v[D]){
                if (A == E || B == E || C == E || D == E) {
                    continue;
                }
                cout<<1<<'\n';
                return 0;
            }

        }
    }
    cout<<0;
    
    return 0;
}