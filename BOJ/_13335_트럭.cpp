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
    
    int n, w, l; //n : 트럭의수, w: 다리의 길이, l:다리의 최대 하중
    cin >> n >> w >> l;
    vector<int> v;
    deque<pair<int,int>> dq; //다리의 있는 트럭 하나의 무게 + 거리
    queue<int> q;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        q.push(a);
        //v.push_back(a); //트럭의 무게
    }



    int cnt = 0;
    while (1) {
        cnt++;
        for (int i = 0; i < dq.size(); i++) {
            dq[i].second++;
        }
        //다리 위에 있는 것들 한칸씩 전진
        if (!dq.empty()) {
            for (int i = 0; i < dq.size(); i++) {
                if (dq[i].second == w) {
                    dq.pop_front();
                }
            }
        }
        if (dq.empty() && q.empty()) {
            cout << cnt;
            return 0;
        }
        
        //현재 다리위에 있는 트럭들의 무게
        int sumOfTruck = 0;
        for (int i = 0; i < dq.size(); i++) {
            sumOfTruck += dq[i].first;
        }
        //다리에 더 올라탈 수 있는 경우
        if (dq.empty()) {
            if (!q.empty()) {
                dq.push_back({ q.front(),0 });
                q.pop();
            }
            
        }
        else {
            if (!q.empty()) {
                if (sumOfTruck + q.front() <= l) {
                    dq.push_back({ q.front(),0 });
                    q.pop();
                }
            }
            
        }
        

    }
    cout << cnt;

    return 0;
}