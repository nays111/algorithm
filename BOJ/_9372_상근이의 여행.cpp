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
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> v[1001];
        for (int i = 0; i < m; i++) {
            int from, to;
            cin >> from >> to;
            v[from].push_back(to);
            v[to].push_back(from);
        }
        cout << n - 1 << '\n';

    }


    return 0;
}