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

int n, l, r;
int arr[51][51];
bool visit[51][51];
int dy[] = { 0,0,-1,1 };
int dx[] = { 1,-1,0,0 };

bool movePeople = false;

void bfs(int y, int x) {
    int peopleCount = arr[y][x];
    queue<pair<pair<int, int>, int>> q;
    q.push({ {y,x},peopleCount });
    visit[y][x] = true;
    int peopleCnt = 0;
    int peopleSum = 0;


    vector<pair<int, int>> v;

    while (!q.empty()) {
        int curY = q.front().first.first;
        int curX = q.front().first.second;
        int curPeopleCnt = q.front().second;
        v.push_back({ curY,curX });


        peopleSum += curPeopleCnt;
        peopleCnt++;

        q.pop();


        for (int i = 0; i < 4; i++) {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            int nextPosPeopleCnt = arr[nextY][nextX];

            if (nextY < 0 || nextX < 0 || nextY >= n || nextX >= n) {
                continue;
            }
            if (visit[nextY][nextX] == false && abs(curPeopleCnt - nextPosPeopleCnt) >= l && abs(curPeopleCnt - nextPosPeopleCnt) <= r) {
                visit[nextY][nextX] = true;
                q.push({ {nextY,nextX}, nextPosPeopleCnt });
                movePeople = true; //인구가 이동했다는 걸 여기서 표시!!
            }
            
        }
    }

    //국경선 열린곳을 한바뀌 돌고나면 값 업데이트
    for (int i = 0; i < v.size(); i++) {
        int y = v[i].first;
        int x = v[i].second;
        arr[y][x] = peopleSum / peopleCnt;
    }
   

}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    int answer = 0;
    //while loop 한번이 하루동안 일어나는 일
    while (1) {
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visit[i][j] == false) {
                    bfs(i, j);
                }
            }
        }
        if (movePeople == true) { //인구이동이 있었으면 하루 증가
            answer++;
            movePeople = false;
        }
        else { //인구이동이 없었다면 다음날도 없으므로 끝
            break;
        }

        //다음날부터는 새로 시작하니깐 방문한 곳 다시 미방문 상태로 초기화
        memset(visit, false, sizeof(visit));
    }
    cout << answer;

    return 0;
}