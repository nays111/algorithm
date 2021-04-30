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

int arr[501][501];
bool visit[501][501];

int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };

int n, m;
int maxSize = 0;


void dfs(int y, int x, int num) {
    visit[y][x] = true;
    arr[y][x] = num;
    maxSize++;

    for (int i = 0; i < 4; i++) {
        int nextY = y + dy[i];
        int nextX = x + dx[i];

        if (nextY < 0 || nextX < 0 || nextY >= n || nextX >= m) {
            continue;
        }

        if (arr[nextY][nextX] != 0 && visit[nextY][nextX] == false) {
            dfs(nextY, nextX, num);
        }
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int num = 1;
    int maxCnt = 0;
    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] != 0 && visit[i][j] == false) {
                dfs(i, j, num);
                num++;
                maxCnt++;
                answer = max(maxSize, answer);
                maxSize = 0;
            }
        }
    }


    cout << maxCnt << '\n' << answer;

    return 0;
}