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
vector<int> dist;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int N,C;
    cin>>N>>C;
    int max = 0;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        vec1.push_back(a);
        if(a>max){
            max = a;
        }
    }
    // 1 2 4 8 9
    // 공유기 3대 설치할 수 있음
    // 거리를 최대한 크게
    // 가장 가까운 두 공유기 사이의 최대 거리
    //1,4,8 또는 1,4,9에 설치하면 가장 인접한 
    //두 공유기 사이의 거리는 3
    
    sort(vec1.begin(),vec1.end());
    int left = 1; //왜 1로 해야 되지?
    int right = max;
    int answer = 0;
    while(left<=right){
        int mid = (left+right)/2;
        int before = 0;//제일 첫번쨰 칸은 공유기를 설치하기 위해 0으로 둠
        int gongNum = 1; //제일 첫번째 칸은 공유기 설치해서 1
        for(int i=1;i<N;i++){
            if(vec1[i]-vec1[before]>=mid){
                before = i;
                gongNum++; //공유기 설치함
            }
        }
        if(gongNum<C){
            right = mid-1;   
        }else{
            left = mid + 1;
        }
        if(gongNum>=C && answer < mid){
            answer = mid;
        }
    }
    cout<<answer;
    return 0;
}