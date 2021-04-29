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

bool flag = false;

bool func(string str) {

    for (int i = 1; i <= str.size() / 2; i++) {
        for (int j = 0; j < str.size() - i; j++) {
            string a = str.substr(j, i);
            string b = str.substr(j+i, i);
            //cout << str << " " << a << " " << b << '\n';
            if (a == b) {
                return false;
            }
        }
    }
    return true;

}

void dfs(string str) {
    if (flag == true) {
        return;
    }
    
    if (func(str) == false) {
        return;
    }

    if (str.size() == n) {
        cout << str;
        flag = true;
        return;
    }
    else {    
        dfs(str + "1");
        dfs(str + "2");
        dfs(str + "3");
    }

}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
   //1,2,3 으로만 이루어져있음 
    
    cin >> n;

    dfs("");



    return 0;
}