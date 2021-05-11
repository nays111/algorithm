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

int n, m, x;

int dist[1001];
int target_to_from[1001];
int from_to_target[1001];
bool visit[1001];
vector<pair<int,int>> v[1001];


struct comp {
    bool operator()(pair<int, int> p1, pair<int, int> p2) {
        return p1.second > p2.second;
    }
};


int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m >> x;


    for (int i = 1; i <= n; i++) {
        dist[i] = INF; //dist 는 i가 x찍도 다시 돌아오는데 걸리는 시간
    }


    for (int i = 0; i < m; i++) {
        int from, to, dist;
        cin >> from >> to >> dist;
        v[from].push_back({ to,dist });
    }
    
    for (int i = 1; i <= n; i++) {
        //다 한번씩 x에 갔다와봐야함
        int from = i;
        dist[from] = 0;
        
        //최단 시간에 가야하므로 거리가 가장 짧은 곳을 찾아가야함
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        pq.push({ from,dist[from] });

        //시작 마을은 방문 체크를 처음에 하지 않는다 -> 다시 돌아왔을 때의 거리를 구해야하므로!

        while (!pq.empty()) {
            int cur_loc = pq.top().first;
            int cur_dist = pq.top().second;
            pq.pop();

            if (visit[cur_loc] == false) {
                visit[cur_loc] = true;
                for (int i = 0; i < v[cur_loc].size(); i++) {
                    int next_loc = v[cur_loc][i].first;
                    int next_dist = v[cur_loc][i].second;
                    
                    if (dist[next_loc] > cur_dist + next_dist) {

                        //cout << next_loc << " " << next_dist << '\n';

                        dist[next_loc] = cur_dist + next_dist;
                        pq.push({ next_loc,cur_dist + next_dist });
                    }

                }
            }
        }
        if (i == x) {
            for (int j= 1; j <= n; j++) {
                target_to_from[j] = dist[j];
            }
        }
        else {
            from_to_target[i] = dist[x];
        }
        

        for (int j = 1; j <= n; j++) {
            //cout << dist[j] << " ";
            dist[j] = INF;
            visit[j] = false;
        }
       // cout << '\n';


    }

    int answer = 0;
    for (int i = 1; i <= n; i++) {
        //cout << from_to_target[i] << " " << target_to_from[i] << '\n';
        answer = max(answer, from_to_target[i] + target_to_from[i]);
    }
    
    cout << answer;

    return 0;
}