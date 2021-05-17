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




int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int arr[101][101] = { 987654321, };
    int item[101];
    int n, m, r;
    cin >> n >> m >> r;


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            arr[i][j] = INF;
        }
    }


    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        item[i] = a;
    }



    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                arr[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < r; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a][b] = c;
        arr[b][a] = c;
    }

    

    //floyd-warshall
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr[i][k] + arr[k][j] < arr[i][j]) {
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                if (arr[i][j] <= m) {
                    cnt += item[j];
                    //cout << item[j] << " ";
                }
            }
        }
        cnt += item[i];
        //cout << cnt << '\n';
        answer = max(answer, cnt);
    }
    cout << answer;





    
    
    return 0;
}