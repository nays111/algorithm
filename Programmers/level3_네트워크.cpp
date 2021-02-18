#include <string>
#include <vector>

using namespace std;
bool visit[201];  
vector<int> v[201];

void dfs(int cur){
    visit[cur]=true;
    for(int i=0;i<v[cur].size();i++){
        int next = v[cur][i];
        if(visit[next]==false){
            dfs(next);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    
    int answer = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j && computers[i][j]==1){
                v[i].push_back(j);
            }
        }
    }
    
    for(int i=0;i<n;i++){
        if(visit[i]==false){
            dfs(i);
            answer++;
        }
    }
    return answer;
}