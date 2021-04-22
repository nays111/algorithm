#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <functional>
#include <string>

#define INF 987654321
using namespace std;
int n,m;
int arr[51][51];
vector<pair<int,int>> virus;
bool checkVirusUsed[51][51];
int emptySpace = 0;

int dist[51][51];
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };
int answer = INF;


void bfs() {
    //checkVirustUsed가 true로 된게 선택한 바이러스
    
    memset(dist, -1, sizeof(dist));

    queue<pair<int, int>> q;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (checkVirusUsed[i][j] == true) {
                q.push({ i,j });
                dist[i][j] = 0;
            }
        }
    }
    //cout << '\n';

    while (!q.empty()) {
        int curY = q.front().first;
        int curX = q.front().second;

        q.pop();
        for (int i = 0; i < 4; i++) {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];


            if (nextY < 0 || nextX < 0 || nextY >= n || nextX >= n) {
                continue;
            }
            if (dist[nextY][nextX] == -1 && arr[nextY][nextX] != 1) {
                //dist 가 -1 이면 방문하지 않은 곳
                q.push({ nextY,nextX });
                
                dist[nextY][nextX] = dist[curY][curX] + 1;
            }

        }
    }
    int cnt = 0;
    int maxTime = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == -1) {
                cnt++;
            }
            maxTime = max(maxTime, dist[i][j]);
        }
    }
    //cout << emptySpace << " " << cnt << '\n';

    if (cnt == emptySpace) {
        //cout << maxTime << '\n';
        answer = min(answer, maxTime);
    }
    





}


void dfs(int cnt, int index) {
    if (cnt == m) {
        bfs();
        return;
    }
    else {
        for (int i = index; i < virus.size(); i++) {
            int y = virus[i].first;
            int x = virus[i].second;

            if (checkVirusUsed[y][x] == false) {
                checkVirusUsed[y][x] = true;
                dfs(cnt+1,i+1);
                checkVirusUsed[y][x] = false;
            }
         
        }
    }


}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
   
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {//바이러스를 미리 바이러스 벡터에 담아둔다.
                virus.push_back({ i,j });
            }
            if (arr[i][j] == 1) {
                emptySpace++;
            }

        }
    }


    dfs(0, 0);
    if (answer == INF) {
        cout << -1;

    }
    else {
        cout << answer;
    }
    

    return 0;
}