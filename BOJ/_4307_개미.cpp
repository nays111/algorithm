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

    for (int i = 0; i < t; i++) {
        int length, n;
        cin >> length >> n;
        vector<int> left;
        vector<int> right;

        vector<int> v;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            v.push_back(a);
        }
        sort(v.begin(), v.end());

        int minTime = 0;
        for (int i = 0; i < v.size(); i++) {
            minTime = max(minTime,min(length - v[i], v[i] ));
        }

        int longTime = max(length - v[0], v[v.size() - 1] );


        cout << minTime << " " << longTime << '\n';

    }








    return 0;
}