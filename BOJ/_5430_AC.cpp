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
        string p;
        cin >> p;

        int n;
        cin >> n;

        string str;
        //char[10000000]
        cin >> str;
        
        deque<int> dq;

        string temp = "";
        for (int i = 0; i < str.size(); i++) {
            if (str[i] >= '0' && str[i] <= '9') {
                temp += str[i];
            }
            else if (str[i] == '[' ) {
                continue;
            }
            else {
                if (temp == "") {
                    continue;
                }
                dq.push_back(stoi(temp));
                temp = "";
            }
            
        }

        bool flag = true;

        bool reverse = false;

        for (int i = 0; i < p.size(); i++) {
            if (p[i] == 'R') {
                reverse = !reverse;
            }
            else if (p[i] == 'D') {
                if (dq.empty()) {
                    flag = false;
                    break;
                }
                else {
                    if (reverse) {
                        dq.pop_back();
                    }
                    else {
                        dq.pop_front();
                    }
                }
            }
        }

        if (flag == false) {
            cout << "error" << '\n';
        }
        else {
            cout << "[";


            if (!reverse) {
                while (!dq.empty()) {
                    if (dq.size() == 1) {
                        cout << dq.front();
                        dq.pop_front();
                    }
                    else {
                        cout << dq.front() << ",";
                        dq.pop_front();
                    }
                }
            }
            else {
                while (!dq.empty()) {
                    if (dq.size() == 1) {
                        cout << dq.back();
                        dq.pop_back();
                    }
                    else {
                        cout << dq.back() << ",";


                        dq.pop_back();
                    }
                }
            }
            


            cout << "]"<<'\n';
        }



    }

    return 0;
}