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

    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        v.push_back(input);
    }
    int max_dp[1001];

    
    for (int i = 0; i < n; i++) {
        max_dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (v[i] > v[j]) {
                max_dp[i] = max(max_dp[j]+1, max_dp[i]);
            }
        }
    }


    int min_dp[1001];
    for (int i = n - 1; i >= 0; i--) {
        min_dp[i] = 1;
        for (int j = n - 1; j > i; j--) {
            if (v[i] > v[j]) {
                min_dp[i] = max(min_dp[j] + 1, min_dp[i]);
            }
        }
    }


    int answer = 0;
    for (int i = 0; i < n; i++) {
        answer = max(answer, min_dp[i] + max_dp[i]);
    }
    cout << answer - 1;



    

    return 0;
}