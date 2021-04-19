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


int arr[51][51];
int temp[51][51];
int n, m, t;

//돌리는 함수
void rotation(int x, int d, int k) {
    for (int i = 1; i <= n; i++) { //원판 번호
        if (i % x == 0) { //x의 배수인경우
            
            deque<int> dq;

            if (d == 0) {//시계 방향인 경우
                
                for (int j = 1; j <= m; j++) {//dq에 우선 옮겨넣는 작업
                    dq.push_back(arr[i][j]);
                }

                for (int j = 0; j < k; j++) { //k칸 회전시킨다.
                    dq.push_front(dq.back());
                    dq.pop_back();
                }
            }
            else if (d == 1) { //반시계 방향인 경우

                for (int j = 1; j <= m; j++) {
                    dq.push_back(arr[i][j]); //dq에 우선 옮겨넣는 작업
                }
                for (int j = 0; j < k; j++) { //k 칸 회전 시킨다.
                    dq.push_back(dq.front());
                    dq.pop_front();
                }

            }

            // 회전시킨 값을 원래 arr에 저장
            for (int j = 1; j <= m; j++) {
                arr[i][j] = dq.front();
                dq.pop_front(); //pop할 때 empty검사 해야하나?
            }

            //remove()


        }
    }
}

//원판에 인접한 수가 남가 있는지 판단하는 함수 
//수 남아있으면 true
//수가 없으면 false
//그때 그때 arr을 업데이트하면 변동이 있으므로, 회전끝나면 한꺼번에
bool decide() {

    bool flag = false;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (temp[i][j] == 0) {
                continue;
            }

            if (i == 1) { //맨 안쪽 원일 경우
                int idx1 = j - 1;
                int idx2 = j + 1;
                if (idx1 == 0) {
                    idx1 = m;
                }
                if (idx2 == m + 1) {
                    idx2 = 1;
                }
                if (arr[i][j] == arr[i][idx1]) {
                    temp[i][j] = 0;
                    temp[i][idx1] = 0;
                    flag =  true;
                }
                else if (arr[i][j] == arr[i][idx2]) {
                    temp[i][j] = 0;
                    temp[i][idx2] = 0;
                    flag = true;
                }
                else if (arr[i][j] == arr[i + 1][j]) {
                    temp[i][j] = 0;
                    temp[i + 1][j] = 0;
                    flag = true;
                }
            }
            else if (i == n) { //맨 바깥쪽 원일 경우
                int idx1 = j - 1;
                int idx2 = j + 1;
                if (idx1 == 0) {
                    idx1 = m;
                }
                if (idx2 == m + 1) {
                    idx2 = 1;
                }
                if (arr[i][j] == arr[i][idx1]) {
                    temp[i][j] = 0;
                    temp[i][idx1] = 0;
                    flag = true;
                }
                else if (arr[i][j] == arr[i][idx2]) {
                    temp[i][j] = 0;
                    temp[i][idx2] = 0;
                    flag = true;
                }
                else if (arr[i][j] == arr[i - 1][j]) {
                    temp[i][j] = 0;
                    temp[i - 1][j] = 0;
                    flag = true;
                }
            }
            else { //맨 안쪽, 바깥쪽을 제외한 원일 경우
                int idx1 = j - 1;
                int idx2 = j + 1;
                if (idx1 == 0) {
                    idx1 = m;
                }
                if (idx2 == m + 1) {
                    idx2 = 1;
                }
                if (arr[i][j] == arr[i][idx1]) {
                    temp[i][j] = 0;
                    temp[i][idx1] = 0;
                    flag = true;
                }
                else if (arr[i][j] == arr[i][idx2]) {
                    temp[i][j] = 0;
                    temp[i][idx2] = 0;
                    flag = true;
                }
                else if (arr[i][j] == arr[i - 1][j]) {
                    temp[i][j] = 0;
                    temp[i - 1][j] = 0;
                    flag = true;
                }
                else if (arr[i][j] == arr[i + 1][j]) {
                    temp[i][j] = 0;
                    temp[i + 1][j] = 0;
                    flag = true;
                }
            }
        }
    }
    
    return flag;
}


//없는 경우에는 원판에 적힌 수의 평균을 구하고, 평균보다 큰 수에서 1을 빼고, 작은 수에는 1을 더한다.
void calculate() {
    int sum = 0;
    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (temp[i][j] != 0) {
                sum+=temp[i][j];
                cnt++;
            }
        }
    }

    double average = (double)sum / cnt;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (temp[i][j] != 0) {
                if (temp[i][j] > average) {
                    temp[i][j]--;
                }
                else if (temp[i][j] < average) {
                    temp[i][j]++;
                }
            }
        }
    }
}

int count() {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] != 0) {
                sum += arr[i][j];
            }
            
        }
    }
    return sum;
}

void copyOriginalToTemp() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            temp[i][j] = arr[i][j];
        }
    }
}
void copyTempToOriginal() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            arr[i][j] = temp[i][j];
        }
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int q = 0; q < t; q++) {
        int x, d, k; //x의 배수인 것들을
        cin >> x >> d >> k;
        rotation(x, d, k);
        //원본을 복사본에 붙혀두기
        copyOriginalToTemp();

        

        if (decide()==false) {
            calculate();
        }
        copyTempToOriginal();


    }

    //답출력
    cout << count();


    return 0;
}