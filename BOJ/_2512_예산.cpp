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
    
    int left = 1;
    int right = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
        right = max(right, a);
    }

    int limit;
    cin >> limit;

    int answer = 0;
    while (left <= right) {
        int mid = (left + right) / 2;

        int sum = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] <= mid) {
                sum += v[i];
            }
            else {
                sum += mid;
            }
        }
        if (sum > limit) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
            answer = mid;
        }

        

    }

    cout << answer;

    

    return 0;
}