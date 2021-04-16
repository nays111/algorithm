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


//하나의 공간에 여러 나무가 생길 수 있음
deque<int> tree[11][11];

//죽은 나무를 저장하는 공간
deque<int> deadTree[11][11];


//각 공간에 저장된 양분의 양
int arr[11][11];

//추가 되는 양분을 저장
int a[11][11];


//번식 방향
int dy[] = { -1,-1,-1,0,0,1,1,1 };
int dx[] = { -1,0,1,-1,1,-1,0,1 };




int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    //주어지는 변수
    int n, m, k;
    cin >> n >> m >> k;

    //추가되는 양분 입력
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    //가장 처음에 양분은 모든 칸에 5만큼 있다.
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            arr[i][j] = 5;
        }
    }
    //나무의 정보
    for (int i = 0; i < m; i++) {
        int a, b, c; // x,y,z
        cin >> a >> b >> c;
        tree[a][b].push_back(c);
    }

    int yearCount = 0;
    while (yearCount < k) {
        //봄
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                //일단 front()를 pop()하고 그 front()를 검사해서 만약 죽으면 dead에 추가, 살아있는 거면 tree의 back에 추가
                int size = tree[i][j].size();
                while (size > 0) {
                    int treeAge = tree[i][j].front();
                    tree[i][j].pop_front();
                    if (treeAge > arr[i][j]) {
                        deadTree[i][j].push_back(treeAge);//죽게되면 죽은 나무에 추가!
                    }
                    else {
                        arr[i][j] -= treeAge;
                        treeAge++;
                        tree[i][j].push_back(treeAge);//나이가 1커진 tree를 다시 tree의 뒤에 추가
                    }
                    size--;
                }
            }
        }


        //여름
        //죽은 나무를 양분으로 바꿨으면 제거해줘야함
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int size = deadTree[i][j].size();

                while (!deadTree[i][j].empty()) {
                    arr[i][j] += (deadTree[i][j].front() / 2);
                    deadTree[i][j].pop_front();
                }
            }
        }

        //가을
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 0; k < tree[i][j].size(); k++) {
                    if (tree[i][j][k] % 5 == 0) {
                        for (int l = 0; l < 8; l++) {
                            int nextX = i + dy[l];
                            int nextY = j + dx[l];
                            if (nextY > n || nextX > n || nextY < 1 || nextX < 1) {
                                continue;
                            }
                            tree[nextX][nextY].push_front(1); //가장 어린 나무가 앞에 가야함 (봄에 나이가 어린 나무부터 양분을 먹기 때문에)
                        }
                    }
                }
            }
        }

        //겨울
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                arr[i][j] += a[i][j];
            }
        }

        yearCount++;

    }
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            answer += tree[i][j].size();
        }
    }
    cout << answer;





    return 0;
}