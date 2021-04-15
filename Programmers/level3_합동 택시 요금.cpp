#include <string>
#include <vector>

#define INF 40000000;
using namespace std;

int dist[201][201];

void floyd(int n){
    for(int k=1;k<=n;k++){ // k는 경유지
        for(int i=1;i<=n;i++){ //i : 시작점
            for(int j=1;j<=n;j++){ //j : 시작점
                if(dist[i][k] + dist[k][j] < dist[i][j]){ //dist[i][k] :i에서 k까지의 비용
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}


int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                dist[i][j] = 0;
            }else{
                dist[i][j] = INF;
            }
        }
    }
    for(auto edge : fares){
        dist[edge[0]][edge[1]] = edge[2];
        dist[edge[1]][edge[0]] = edge[2];
    }
    floyd(n);
    
    
    for(int k=1;k<=n;k++){
        answer=  min(answer,dist[s][k] + dist[k][a] + dist[k][b]);
    }
    
    
    
    return answer;
}