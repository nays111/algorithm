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
        int n;
        cin >> n;
        vector<string> v;
        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;
            v.push_back(str);

        }
        sort(v.begin(), v.end());

        bool flag = true;
        for (int i = 0; i < v.size() - 1; i++) {

            string target = v[i];
            string compareTarget = v[i + 1];

            if (target.size() > compareTarget.size()) {
                continue;
            }
            if (compareTarget.find(target) == 0) {

                flag = false;
                cout << "NO" << '\n';

                break;
            }
        }
        if (flag == true) {
            cout << "YES" << '\n';
        }

            
        

    }


    return 0;
}