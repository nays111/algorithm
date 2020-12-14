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
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int N;
        cin>>N;
        int tree[N];
        for(int j=0;j<N;j++){
            cin>>tree[j];
        }
        sort(tree,tree+N);
        int result = 0;
        for(int k=0;k<N-2;k++){
            int c = tree[k+2]-tree[k];
            result = max(c,result);
        }
        cout<<result<<endl;
        
    }

 
    return 0;

}