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

int t;
int player[11][11];
int answer = 0;
bool visit_player[11];
//포지션마다 한명씩 
void dfs(int sum,int cnt) {
    if (cnt == 11) {
        //cout << sum << " ";
        answer = max(answer, sum);
        return;
    }

    for (int i = 0; i < 11; i++) {
        if (player[cnt][i] == 0) {
            continue;
        }

        if (visit_player[i] == false) {
            visit_player[i] = true;
            dfs(sum + player[cnt][i], cnt + 1);
            visit_player[i] = false;
        }
    }
    

    


}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> t;
    

    while (t--) {
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 11; j++) {
                cin >> player[i][j];
            }
        }

        dfs(0,0);
        memset(visit_player, false, sizeof(visit_player));
        cout << answer << '\n';
        answer = 0;

    }
    
    

    return 0;
}