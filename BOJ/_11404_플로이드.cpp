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


#define INF 100000000;
int arr[101][101];


int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);


    

    int n, m;
    cin >> n >> m;

    

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                arr[i][j] = 0;
            }
            else {
                arr[i][j] = INF;
            }
        }
    }
    
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost; 
        arr[from][to] = min(arr[from][to], cost); //cost 가 작은걸 넣어줘야함 같은 경로일 경우에
        //arr[to][from] = cost;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr[i][j] > arr[i][k] + arr[k][j]) {
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] == 100000000) {
                arr[i][j] = 0;
            }
            
            cout << arr[i][j] << " ";
            
            
        }
        cout << '\n';
    }


    

    return 0;
}