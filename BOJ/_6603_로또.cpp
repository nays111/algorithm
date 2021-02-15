#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <functional>
using namespace std;


int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    while(1){
        int n;
        cin>>n;
        if(n==0){
            break;
        }
        vector<int> arr(n);
        vector<int> np(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n-6;i++){
            np[n-i-1]=1;
        }
        sort(arr.begin(),arr.end());
        do{
            for(int i=0;i<n;i++){
                if(np[i]==0){
                    cout<<arr[i]<<" ";
                }
            }
            cout<<'\n';
        }while(next_permutation(np.begin(),np.end()));
        cout<<'\n';
    }
    
    
    
    return 0;
}