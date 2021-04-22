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
        int s1, s2;
        cin >> s1;
        set<int> s;
        for (int j = 0; j < s1; j++) {
            int a;
            cin >> a;
            s.insert(a);
        }
        cin >> s2;
        for (int j = 0; j < s2; j++) {
            int a;
            cin >> a;
            if (s.find(a) == s.end()) {
                cout << 0 << '\n';

            }
            else {
                cout << 1 << '\n';
            }
        }


    }
   

    

    return 0;
}