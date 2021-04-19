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
vector<int> v;

bool isPrime(int n) {
    if (n < 2) {
        return false;
    }
    else {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
    }
    return true;
}




int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    //1~n까지 수 중에서 소수인 것만 벡터에 담기
    
    for (int i = 1; i <= n; i++) {
        if (isPrime(i) == true) {
            v.push_back(i);
        }
    }

    int siz = v.size();

    //투포인터 사용
    int start = 0;
    int end = 0;
    int answer = 0;
    int sum = 0;
    while (1) {
        if (sum >= n) {
            sum -= v[start];
            start++;
        }
        else if(end==siz){
            break;
        }
        else {
            sum += v[end];
            end++;
        }
        if (sum == n) {
            answer++;
        }


    }
    cout << answer;
     



    return 0;
}