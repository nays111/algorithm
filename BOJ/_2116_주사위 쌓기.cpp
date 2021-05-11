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


int arr[10001][6];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    /*
    맨 아래가 1번
    서로 붙어 있는 두 개의 주사위에서 아래에 있는 주사위의 윗면에 적혀있는 숫자는 위에 있는 주사위의 아랫면에 적혀있는 숫자와 같다
    4개 중 합 최대?
    */
    int n;
    cin >> n;
    int answer = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < 6; i++) { // 맨 아래꺼 뭐로 정할지
        int first_top = arr[0][i];
        int top = i;

        vector<int> temp[10001];
        for (int j = 1; j < n; j++) {

            for (int k = 0; k < 6; k++) {
                if (first_top == arr[j][k]) {
                    //cout << first_top << '\n';
                    switch (k)
                    {
                    case 0:
                        first_top = arr[j][5];
                        temp[j].push_back(arr[j][1]);
                        temp[j].push_back(arr[j][2]);
                        temp[j].push_back(arr[j][3]);
                        temp[j].push_back(arr[j][4]);
                        break;
                    case 1:
                        first_top = arr[j][3];
                        temp[j].push_back(arr[j][0]);
                        temp[j].push_back(arr[j][2]);
                        temp[j].push_back(arr[j][4]);
                        temp[j].push_back(arr[j][5]);
                        break;
                    case 2:
                        first_top = arr[j][4];
                        temp[j].push_back(arr[j][0]);
                        temp[j].push_back(arr[j][1]);
                        temp[j].push_back(arr[j][3]);
                        temp[j].push_back(arr[j][5]);
                        break;
                    case 3:
                        first_top = arr[j][1];
                        temp[j].push_back(arr[j][0]);
                        temp[j].push_back(arr[j][2]);
                        temp[j].push_back(arr[j][4]);
                        temp[j].push_back(arr[j][5]);
                        break;
                    case 4:
                        first_top = arr[j][2];
                        temp[j].push_back(arr[j][0]);
                        temp[j].push_back(arr[j][1]);
                        temp[j].push_back(arr[j][3]);
                        temp[j].push_back(arr[j][5]);
                        break;
                    case 5:
                        first_top = arr[j][0];
                        temp[j].push_back(arr[j][1]);
                        temp[j].push_back(arr[j][2]);
                        temp[j].push_back(arr[j][3]);
                        temp[j].push_back(arr[j][4]);
                        break;
                    }
                    break;
                }
            }
        

        }

        if (i == 0) {
            temp[0].push_back(arr[0][1]);
            temp[0].push_back(arr[0][2]);
            temp[0].push_back(arr[0][3]);
            temp[0].push_back(arr[0][4]);
        }
        else if (i == 1) {
            temp[0].push_back(arr[0][0]);
            temp[0].push_back(arr[0][2]);
            temp[0].push_back(arr[0][4]);
            temp[0].push_back(arr[0][5]);
        }
        else if (i == 2) {
            temp[0].push_back(arr[0][0]);
            temp[0].push_back(arr[0][1]);
            temp[0].push_back(arr[0][3]);
            temp[0].push_back(arr[0][5]);
        }
        else if (i == 3) {
            temp[0].push_back(arr[0][0]);
            temp[0].push_back(arr[0][2]);
            temp[0].push_back(arr[0][4]);
            temp[0].push_back(arr[0][5]);
        }
        else if (i == 4) {
            temp[0].push_back(arr[0][0]);
            temp[0].push_back(arr[0][1]);
            temp[0].push_back(arr[0][3]);
            temp[0].push_back(arr[0][5]);
        }
        else if (i == 5) {
            temp[0].push_back(arr[0][1]);
            temp[0].push_back(arr[0][2]);
            temp[0].push_back(arr[0][3]);
            temp[0].push_back(arr[0][4]);
        }

        int temp_sum = 0;
        for (int j = 0; j < n; j++) {
            int biggest = 0;
            for (int k = 0; k < temp[j].size(); k++) {
                //cout << temp[j][k] << " ";
                biggest = max(biggest, temp[j][k]);
            }
            temp_sum += biggest;
        }
        answer = max(temp_sum, answer);
        //cout << '\n';
    }
    cout << answer;
    
    

    return 0;
}