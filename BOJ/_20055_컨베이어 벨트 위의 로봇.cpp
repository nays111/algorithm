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
    int n, k;
    cin >> n >> k;
    deque<pair<int,int>> dq; //내구도, 로봇이 위치해있는지의 여부
    
    for (int i = 0; i < 2 * n; i++) {
        int a;
        cin >> a;
        dq.push_back({ a,0 });
    }
    int cnt = 1;

    while (1) {
        pair<int, int> p = dq.back();
        dq.pop_back();
        dq.push_front(p);
        //돌렸을 때 내려야할 로봇있으면 내린다.
        if (dq[n - 1].second == 1) {
            dq[n - 1].second = 0;
        }
        //가장 먼저 벨트에 올라간 로봇부터!!
        for (int i = n-2; i>=0; i--) {
            if (dq[i + 1].first > 0 && dq[i + 1].second == 0 && dq[i].second == 1) {
                dq[i].second = 0;
                dq[i + 1].second = 1;
                dq[i + 1].first--;
            }
        }
        if (dq[n - 1].second == 1) {
            dq[n - 1].second = 0;
        }
        if (dq[0].second == 0 && dq[0].first > 0) {
            dq[0].second = 1;
            dq[0].first--;

        }
        int num = 0;
        for (int i = 0; i < 2*n; i++) {
            if (dq[i].first == 0) {
                num++;
            }
        }
        if (num >= k) {
            cout << cnt;
            return 0;
        }
        cnt++;

    }
    cout << cnt;



    

    return 0;
}