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

    int h, w;
    cin >> h >> w;


    bool arr[501][501] = { false, };

    vector<int> v;

    int highest = 0;
    

    for (int i = 0; i < w; i++) {
        int input;
        cin >> input;
        v.push_back(input);
    }


    int answer = 0;
    for (int i = 1; i < v.size()-1; i++) {
        int target = v[i];

        //좌측으로 검사
        int left = 0;
        int right = 0;

        for (int j = i - 1; j >= 0; j--) {
            left = max(left, v[j]);
        }

        //우측으로 검사
        for (int j = i + 1; j < v.size(); j++) {
            right = max(right, v[j]);
        }
        //cout << left << " " << right << '\n';
        
        int minHeight = min(left, right);
        
        

        int cnt;
        if (minHeight - target < 0) {
            cnt = 0;
        }
        else {
            cnt = minHeight - target;
        }
        answer += cnt;



    }
    cout << answer;



    

    return 0;
}