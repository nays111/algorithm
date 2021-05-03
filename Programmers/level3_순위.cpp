#include <string>
#include <vector>
#include <iostream>
using namespace std;

int arr[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for(int i=0;i<results.size();i++){
        int from = results[i][0];
        int to = results[i][1];
        arr[from][to] = 2; //이겼다
        arr[to][from] = 1; //졌다.
    }
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(arr[i][k] == 2 && arr[k][j]==2){
                    arr[i][j] = 2;
                    arr[j][i] = 1;
                }
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        int cnt = 0;
        
        for(int j=1;j<=n;j++){
            if(i==j){
                continue;
            }else{
                if(arr[i][j]==1 || arr[i][j]==2){
                    cnt++;
                }
            }
        }
        if(cnt == n-1){
            answer++;
        }
    }
    
    return answer;
}