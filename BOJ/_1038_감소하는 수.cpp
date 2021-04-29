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

    queue<string> q;
    int cnt = -1;
    for (int i = 0; i <= 9; i++) {
        q.push( to_string(i));
    }
    
    while (!q.empty()) {
        string curNum = q.front();
        
        cnt++;
 
        q.pop();
        if (cnt == n) {
            cout << curNum;
            return 0;
        }
        for (int i = 0; i <= 9; i++) {
            if (i >= (curNum[curNum.size()-1]-'0') ) {
                continue;
            }
            else {
                string nextNum = curNum + to_string(i);
                q.push(nextNum);
            }
            
        }



    }
    cout << -1;



    return 0;
}