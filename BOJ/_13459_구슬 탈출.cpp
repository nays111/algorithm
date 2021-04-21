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

int n, m; // n : 세로, m : 가로
//각 칸에 빨강 or 파랑 구슬
//빨강 구슬을 구멍을 통해 빼야함
//파랑 구슬은 구멍에 들어가면 안댐

//왼쪽으로 기울이기, 오른쪽으로 기울이기, 위쪽으로 기울이기, 아래쪽으로 기울이기 - 4가지 동작
//공은 동시에 이동

//빨간 구슬이 구멍에 빠지면 성공, but 파랑 구슬이 구명에 빠지면 실패
//동시에 구멍에 빠져도 실패
//동시에 같은 칸에 있을 수 없음
//기울이는 동작을 그만하는 것은 더 이상 구슬이 움직이지 않을 때 까지이다.
//10번 이하로 빨간 구슬을 구멍을 통해 빼낼 수 있나?
//빼낼 수 있으면 1, 없으면 0
//. : 빈칸 , # : 벽, o : 구멍, R : 빨간 구슬 위치, B : 파란 구슬 위치
char arr[11][11];
bool visit[11][11][11][11];
int redY, redX, blueY, blueX;

int targetY, targetX;
int answer = 0;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void move(int& nextRedY ,int& nextRedX, int& redMove ,int dy, int dx) {
    while (arr[nextRedY][nextRedX] != 'O' && arr[nextRedY + dy][nextRedX + dx] != '#') {
        nextRedX += dx;
        nextRedY += dy;
        redMove++;
    }
}


void bfs() {

    queue<pair<pair<pair<int, int>, pair<int, int>>,int>> q; //redY,redX,blueY,blueX,count
    q.push({ {{redY,redX},{blueY,blueX}},0 });
    visit[redY][redX][blueY][blueX] = true;

    while (!q.empty()) {
        int curRedY = q.front().first.first.first;
        int curRedX = q.front().first.first.second;
        int curBlueY = q.front().first.second.first;
        int curBlueX = q.front().first.second.second;
        int curDist = q.front().second;
        q.pop();

        if (curDist >= 10) {
            answer = 0;
            break;
        }


        for (int i = 0; i < 4; i++) {
            int nextRedY = curRedY;
            int nextRedX = curRedX;
            int nextBlueY = curBlueY;
            int nextBlueX = curBlueX;
            int nextDist = curDist + 1;

            int redMove = 0;
            int blueMove = 0;
            move(nextRedY, nextRedX, redMove,dy[i], dx[i]);
            move(nextBlueY, nextBlueX, blueMove, dy[i], dx[i]);

            if (arr[nextBlueY][nextBlueX] == 'O') {
                continue;
            }
            if (arr[nextRedY][nextRedX] == 'O') {
                answer = 1;
                return;
            }

            //파랑공이랑 빨강공이 같은 위치면 거리 비교해서 짧은걸 한칸 뒤로
            if (nextRedY == nextBlueY && nextRedX == nextBlueX) {
                if (redMove <= blueMove) {
                    nextBlueY -= dy[i];
                    nextBlueX -= dx[i];
                }
                else {
                    nextRedY -= dy[i];
                    nextRedX -= dx[i];
                }
            }

            //이미 방문한곳이면 pass
            if (visit[nextRedY][nextRedX][nextBlueY][nextBlueX] == true) {
                continue;
            }

            q.push({ {{nextRedY,nextRedX},{nextBlueY,nextBlueX}},nextDist });
            visit[nextRedY][nextRedX][nextBlueY][nextBlueX] = true;

        }

    }


}




int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++) {
            arr[i][j] = str[j];
        }
    }

    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 'R') {
                redY = i;
                redX = j;
            }
            if (arr[i][j] == 'B') {
                blueY = i;
                blueX = j;
            }
            if (arr[i][j] == 'O') {
                targetY = i;
                targetX = j;
            }
        }
    }
    bfs();
    cout << answer;
    

    

    return 0;
}