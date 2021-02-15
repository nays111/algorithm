#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <stack>
#include <queue>
#include <map>
#include <functional>
using namespace std;


int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    int arr[100001];
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        arr[i+1] = arr[i] + a;
    }

    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        cout << arr[b]-arr[a-1] << '\n';
    }

    
    
    return 0;
}