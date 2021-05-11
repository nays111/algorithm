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

int n, m;
int dy[] = { 0,0,-1,1 };
int dx[] = { 1,-1,0,0 };
char arr[21][21];
bool visit[21][21][21][21];
/*
o : 동전
. : 빈 칸
# : 벽
두 개의 빈 칸에는 동전이 하나씩 놓여져 잇고, 두 동전의 위치는 다르다.
버튼은 "왼쪽","오른쪽","위","아래" 4가지
버튼을 누르면 두 동전이 버튼에 쓰여있는 방향으로 동시에 이동
1) 동전이 이동하려는 칸이 벽이면, 동전은 이동하지 않는다.
2) 동전이 이동하려는 방향에 칸이 없으면 동전은 보드 바깥으로 떨어진다.
3) 그 외의 경우에는 이동하려는 방향으로 한 칸 이동한다. 이동하려는 칸에 동전이 있는 경우에도 한 칸 이동한다.

두 동전 중 하나만 보드에서 떨어뜨리기 위해 버튼을 최소 몇번 눌러야하는지?
버튼을 10번보다 많이 눌러야 한다면, -1 출력
*/

int drop_count(int ny1, int nx1, int ny2, int nx2) {
    int cnt = 0;

    if (ny1 < 0 || nx1 < 0 || ny1 >= n || nx1 >= m) {
        //1번 coin이 떨어지는 경우
        cnt++;
    }
    if (ny2 < 0 || nx2 < 0 || ny2 >= n || nx2 >= m) {
        //2번 coin이 떨어지는 경우
        cnt++;
    }

    return cnt;

}

typedef struct Coin {
    int y1;
    int x1;
    int y2;
    int x2;
    int cnt;
}Coin;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;


    int coin_cnt = 0;
    int y1 = 0; 
    int x1 = 0;
    int y2 = 0;
    int x2 = 0;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < str.size(); j++) {
            arr[i][j] = str[j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (coin_cnt == 0) {
                if (arr[i][j] == 'o') {
                    y1 = i;
                    x1 = j;
                    coin_cnt++;
                }

            }
            else if (coin_cnt == 1) {
                if (arr[i][j] == 'o') {
                    y2 = i;
                    x2 = j;
                }
            }
        }
    }


    //cout << y1 << " " << x1 << " " << y2 << " " << x2 << '\n';
    queue<Coin> q;
    q.push({ y1,x1,y2,x2,0 });
    visit[y1][x1][y2][x2] = true;

    while (!q.empty()) {
        int y1 = q.front().y1;
        int x1 = q.front().x1;
        int y2 = q.front().y2;
        int x2 = q.front().x2;
        int cur_cnt = q.front().cnt; //현재까지 클릭한 버튼 횟수

        if (cur_cnt > 10) {
            cout << -1;
            return 0;
        }

        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny1 = y1 + dy[i];
            int nx1 = x1 + dx[i];
            int ny2 = y2 + dy[i];
            int nx2 = x2 + dx[i];

            if (arr[ny1][nx1] == '#') {//벽이면 이동하지 않는다
                ny1 = y1;
                nx1 = x1;
            }

            if (arr[ny2][nx2] == '#') {//벽이면 이동하지 않는다
                ny2 = y2;
                nx2 = x2;
            }
            //두 동전을 모두 떨어뜨리는 경우는 continue 해야함
            if (drop_count(ny1, nx1, ny2, nx2) == 2) {
                continue;
            }

            //한 동전만 떨어지는 경우 성공이므로 break
            if (drop_count(ny1, nx1, ny2, nx2) == 1) {
                if (cur_cnt + 1 > 10) {
                    cout << -1;
                    return 0;
                }
                else {
                    //cout << ny1 << nx1 << ny2 << nx2 << '\n';
                    cout << cur_cnt + 1;
                    return 0;
                }
            }

            //방문하지 않은 경우에는 방문
            if (visit[ny1][nx1][ny2][nx2] == false) {
                visit[ny1][nx1][ny2][nx2] = true;
                q.push({ ny1,nx1,ny2,nx2,cur_cnt + 1 });
            }



        }

    }
    cout << -1;


    return 0;
}