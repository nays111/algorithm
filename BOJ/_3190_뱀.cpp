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

int n, k;
int arr[101][101];
queue<pair<int, char>> q;
int l;


struct snake{
    int y;
    int x;
};


//dir
//1 :오른쪽
//2 : 왼쪽
//3 : 위쪽
//4 : 아래쪽
int turn(int dir,char ch) {
    if (ch == 'L') {
        if (dir == 1) { //오른쪽을 지금 바라보고 있으면
            return 3;
        }
        else if (dir == 2) { //왼쪽을 바라고있는 상태에서 왼쪽 회전
            return 4;
        }
        else if (dir == 3) {
            return 2;
        }
        else if (dir == 4) {
            return 1;
        }
    }
    else if (ch == 'D') {
        if (dir == 1) {
            return 4;
        }
        else if (dir == 2) {
            return 3;
        }
        else if (dir == 3) {
            return 1;
        }
        else if (dir == 4) {
            return 2;
        }
    }
}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int y, x;
        cin >> y >> x;
        y--;
        x--;
        arr[y][x] = -1; //사과의 위치

    }

    cin >> l;
    for (int i = 0; i < l; i++) {
        int x;
        char c;
        cin >> x >> c;
        q.push({ x,c });
    }
    
    deque<snake> dq;
    //dir
    //1 :오른쪽
    //2 : 왼쪽
    //3 : 위쪽
    //4 : 아래쪽
    int direction = 1;
    dq.push_back({0,0});
    arr[0][0] = 1;

    int time = 0;

    while (1) {
        time++;
        int curY = dq.front().y;
        int curX = dq.front().x;

        if (!q.empty()) {
            if (time == q.front().first+1) {
                direction = turn(direction, q.front().second);
                q.pop();
            }
        }
        
        int nextY, nextX;
        if (direction == 1) {
            nextY = curY;
            nextX = curX + 1;
        }
        else if (direction == 2) {
            nextY = curY;
            nextX = curX - 1;
        }
        else if (direction == 3) {
            nextY = curY - 1;
            nextX = curX;
        }
        else if (direction == 4) {
            nextY = curY + 1;
            nextX = curX;
        }

        //벽에 부딪히는 경우
        if (nextY < 0 || nextX < 0 || nextY >= n || nextX >= n) {
            break;
        }

        //자기 몸에 부딪히는 경우
        if (arr[nextY][nextX] == 1) {
            break;
        }


        if (arr[nextY][nextX] == -1) {
            //사과만나면
            dq.push_front({ nextY, nextX });
            arr[nextY][nextX] = 1;
        }
        else {
            //cout << time;
            dq.push_front({ nextY, nextX });
            arr[nextY][nextX] = 1;
            arr[dq.back().y][dq.back().x] = 0;
            dq.pop_back();
            
        }




        
    }

    cout << time;


    
    return 0;
}