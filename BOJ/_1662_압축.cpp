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

    string str;
    cin >> str;

    stack<pair<char,int>> st;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ')') {
            int pattern_size = 0;
            while (st.top().first != '(' && !st.empty()) {
                pattern_size += st.top().second;
                st.pop();
            }
            st.pop(); //'(' 제거
            int pattern_to_repeat = st.top().first - '0';
            int repeat_size = pattern_size * pattern_to_repeat;
            st.pop();
            st.push({ '.',repeat_size });


        }
        else {
            st.push({ str[i],1 });
        }
    }
    int answer = 0;
    while (!st.empty()) {
        answer += st.top().second;
        //cout << st.top().second << " ";
        st.pop();
    }
    cout << answer;

    return 0;
}