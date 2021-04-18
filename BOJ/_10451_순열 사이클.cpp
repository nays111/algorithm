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

bool visit[1001];
int arr[1001];
int cnt = 0;
void dfs(int start,int initialStart) {

    int end = arr[start];
    if (end == initialStart) {
        cnt++;
    }

    if (visit[end] == false) {
        visit[end] = true;
        dfs(end,initialStart);
    }
}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        //순열 사이클의 개수는 연결 요소의 개수?
        
        vector<int> v[1001];
        for (int j = 1; j <= n; j++) {
            cin >> arr[j];
        }

        for (int j = 1; j <= n; j++) { //j 자체가 출발지점
            if (visit[j] == false) {
                visit[j] = true;
                dfs(j, j);

            }
        }
        cout <<cnt << '\n';
        cnt = 0;
        memset(arr, 0, sizeof(arr));
        memset(visit, false, sizeof(visit));
    }

    return 0;
}