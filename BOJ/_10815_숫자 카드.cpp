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
    int N;
    cin>>N;
    vector<int> vec1;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        vec1.push_back(a);
    }
    sort(vec1.begin(),vec1.end());
    int M;
    cin>>M;
    vector<int> vec2;
    for(int i=0;i<M;i++){
        int target;
        cin>>target;
        vec2.push_back(target);
        int left = 0;
        int right = N-1;
        int answer = 0;
        while(left<=right){
            int mid = (left+right)/2;
            if(vec1[mid]==target){
                answer = 1;
                break;
            }else if(vec1[mid]>target){
                right = mid-1;
            }else{
                left = mid + 1;
            }
        }
        cout<<answer <<" ";
    }

    return 0;

}