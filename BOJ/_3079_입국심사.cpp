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
    long long n, m;
    cin >> n >> m;
    vector<long long> time;

    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        time.push_back(a);
    }
    sort(time.begin(), time.end());
    long long right = (long long)time[time.size() - 1] * m;

    //right = right * n;
    //max(right)는  x 최대 time
    long long left = 1;
    long long answer = 0;
    while (left <= right) {
        long long mid = (left + right) / 2;


        long long sum = 0;
        for (int i = 0; i < time.size(); i++) {
            sum += (long long)(mid / time[i]);
        }

        if (sum < m) {
            //mid를 높여야함
            left = mid + 1;
            
        }
        else {
            right = mid - 1;
            answer = mid;
        }
    }

    cout << answer;
    

    return 0;
}