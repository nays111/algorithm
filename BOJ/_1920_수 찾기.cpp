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
vector<int> vec1;
vector<int> vec2;
//이진탐색
int binarySearch(int low,int high,int target){
    if(low>high){
        return 0;
    }else{
        int mid = (low+high)/2; //중간값
        if(vec1[mid]==target){//찾으려는 값이 딱 중간에 있으면
            return 1;
        }else if(vec1[mid]>target){//찾으려는 값이 왼쪽에 있는 경우
            return binarySearch(low,mid-1,target);
        }else{//찾으려는 값이 오른쪽에 있는 경우
            return binarySearch(mid+1,high,target);
        }
    }
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int N,M;
    cin>>N;

    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        vec1.push_back(a);
    }
    sort(vec1.begin(),vec1.end());
    cin>>M;
    for(int i=0;i<M;i++){
        int a;
        cin>>a;
        vec2.push_back(a);
        cout<<binarySearch(0,N-1,a)<<'\n';
    }

    return 0;

}