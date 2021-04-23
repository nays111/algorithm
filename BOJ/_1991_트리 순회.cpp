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

int n;
char arr[27][2];

string a, b, c;//전위, 중위, 후위 결과

//전위는 root -> 왼쪽 -> 오른쪽
void pre(char ch) {
    if (ch == '.') {
        return;
    }
    else {
        a += ch;
        pre(arr[ch-'A'][0]);
        pre(arr[ch-'A'][1]);
    }
}

void in(char ch) {
    if (ch == '.') {
        return;
    }
    else {
        in(arr[ch - 'A'][0]);
        b += ch;
        in(arr[ch - 'A'][1]);
    }
}

void post(char ch) {
    if (ch == '.') {
        return;
    }
    else {
        post(arr[ch - 'A'][0]);
        post(arr[ch - 'A'][1]);
        c += ch;
    }
}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
       char root, left, right;
       cin >> root >> left >> right;
       arr[root-'A'][0] = left;
       arr[root-'A'][1] = right;
    }
    pre('A');
    in('A');
    post('A');
    cout << a << '\n' << b << '\n' << c;
    

    return 0;
}