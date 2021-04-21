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

using namespace std;
//바이러스는 활성 상태와 비활성 상태가 있음
//처음에 모든 바이러스는 비활성 상태
//활성 상태 바이러스는 상하좌우로 동시에 복제(1초 소모)
//바이러스 M개를 활성 상태로 변경하려한다.

//0 빈칸, 1 벽, 2 바이러스 위치
//활성 바이러스가 비활성 바이러스 있는 칸으로 가면 비활성 바이러스가 활성으로 변한다.


//2인 것들 중 M개를 활성 바이러스 바꿔야함 -> dfs
//바꾼 상태에서 bfs 돌려본다

int n, m;
int arr[51][51];
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };
int totalEmptyCnt = 0;


vector<pair<int,int>> virus;
bool visit[51][51]; //활성화 바이러스를 뭐로 체크했는지 확인하기 위한 상태

bool check[51][51]; //바이러스가 퍼지는걸 체크

int answer = 987654321;


int dist[51][51] = { -1, };


//바이러스가 다 퍼졌는지 확인하는 함수
bool checkSpread() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 0 && check[i][j] == false) {
                //벽도 아닌데 바이러스가 안퍼진곳이 있으면 false;
                return false;
            }
        }
    }
    return true;
}


void bfs() {
    queue <pair<int,int>> q;
    memset(dist, -1, sizeof(dist));



    //visit = true처리되어있는 곳들이 활성바이러스
    for (int i = 0; i < virus.size(); i++) {
        int y = virus[i].first;
        int x = virus[i].second;
        if (visit[y][x] == true) {
            //활성화 바이러스 찾으면 얘네를 큐에 넣고 검사 시작
            q.push( {y,x} );
            dist[y][x] = 0; //활성 바이러스는 0으로 시작
        }
    }
    int cnt = 0; //빈 공간 카운트
    int maxTime = 0;

    //bfs 탐색 시작
    while (!q.empty()) {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();


        for (int i = 0; i < 4; i++) {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];

            //범위를 벗어나는 경우
            if (nextY < 0 || nextX < 0 || nextY >= n || nextX >= n) {
                continue;
            }
    

            if (arr[nextY][nextX] != 1 && dist[nextY][nextX] == -1) {
                //dist 가 -1인 곳은 방문하지 않은 곳, arr가 1인곳은 벽이므로 못감
                dist[nextY][nextX] = dist[curY][curX] + 1;

                //그냥 빈곳일 때랑, 바이러스(비활성화 바이러스) 일 때가 있음
                if (arr[nextY][nextX] == 0) {
                    //그냥 빈곳일 때는
                    cnt++;
                    //어차피 BFS니깐 제일 마지막 찍히는 값이 가장 오래 걸린 시간임
                    maxTime = dist[nextY][nextX];
                    
                }
                q.push({ nextY,nextX });
            }

        }
    }



    if (totalEmptyCnt == cnt) {
        //maxTime 중에 가장 적은 것이 답!
        answer = min(answer, maxTime);
    }
    
    
    

}

//바이러스들 중 어떤 것을 활성화 바이러스로 고를지!!
void dfs(int index,int cnt) {
    if (cnt == m) {
        bfs();
        return;
    }
    else {
        for (int i = index; i < virus.size(); i++) {
            int y = virus[i].first;
            int x = virus[i].second;
            if (visit[y][x] == false) {
                visit[y][x] = true;
                dfs(i+1,cnt + 1);
                visit[y][x] = false;
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
            if (arr[i][j] == 2) {
                virus.push_back({ i,j });
            }
            if (arr[i][j] == 0) {
                totalEmptyCnt++;
            }
        }
    }

    dfs(0,0);
    if (answer == 987654321) {
        cout << -1;
    }
    else {
        cout << answer;
    }

    

    return 0;
}