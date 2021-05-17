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



int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int arr[501][501] = { 0, };

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 2; //a는 b보다 작다. (2)
        arr[b][a] = 1; //b는 a보다 크다. (1)
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr[i][k] == 2 && arr[k][j] == 2) {
                    arr[i][j] = 2;
                    arr[j][i] = 1;
                }
            }
        }

    }
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        bool flag = true;
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                if (arr[i][j] == 0) {
                    flag = false;
                }
            }
        }
        if (flag == true) {
            answer++;
        }
        //cout << '\n';
    }


    cout << answer;
    
    return 0;
}