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

    int n, s;
    vector<int> v;

    cin >> n >> s;
    
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    int answer = n+1;
    int start = 0;
    int end = 0;
    int sum = v[0]; //맨 앞에꺼 sum에 추가시켜두고 시작
    while (start <= end && end < n) {

        if (sum < s) {
            end++;
            sum += v[end];
        }
        else {
            answer = min(answer,end - start + 1);
            sum -= v[start];
            start++;

        }
    }
    if (answer == n + 1) {
        cout << 0;
    }
    else {
        cout << answer;
    }
    

    return 0;
}