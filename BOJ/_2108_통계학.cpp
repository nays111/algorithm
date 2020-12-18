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
int arr[8002];
double sansulAvg(vector<int> v){
    double sum = 0;
    for(int i=0;i<v.size();i++){
        sum+=v[i];
    }
    
    if(to_string(round(sum/(double)v.size()))=="-0"){
        return 0;
    }else{
        return round(sum/(double)v.size());
    }
}

int middleVal(vector<int> v){
    sort(v.begin(),v.end());
    int mid = v.size()/2;
    return v[mid];
}
//사용자 정의 정렬 함수
//정렬할때 sort(begin(),end(),compareSort)
//begin()와 end() 는 &로 받아줘야함
bool compareSort(const pair<int, int> &v1, const pair<int,int> &v2){
    if(v1.second==v2.second){// 빈도수가 만약에 같다면
        return v1.first<v2.first;
    }
    return v1.second>v2.second; //아니면 내림 차순    
}
int mostVal(vector<int> v){
    vector<pair<int,int>> v2;
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        if(v2.empty()){
            v2.push_back(make_pair(v[i],1)); //맨처음꺼만 넣기
            continue;
        }
        if(v2.back().first == v[i]){
            pair<int,int> temp = v2.back();
            temp.second++;
            v2.pop_back();
            v2.push_back(temp);
        }else{
            v2.push_back(make_pair(v[i],1));
        }
    }
    //빈도수는(second) 높은순서대로(1순위) v[i]는 작은 순서대로 정렬(2순위)
    //사용자정의 정렬 함수를 만들어야할듯
    sort(v2.begin(),v2.end(),compareSort);
    //어차피 두번째로 큰수는 [1].second에 있음
    if(v2[0].second == v2[1].second){
        //만약 빈도수가 같으면
        return v2[1].first;
    }else{
        return v2[0].first;
    }
}

int rangeVal(vector<int> v){
    sort(v.begin(),v.end());
    return v[v.size()-1]-v[0];
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin>>N;
    vector<int> v;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        v.push_back(a);
        arr[a+4000]++;//음수값이 나올수도 있으니깐
    }
    cout<<sansulAvg(v)<<endl;
    //printf("%1.lf\n",sansulAvg(v));
    cout<<middleVal(v)<<endl;
    cout<<mostVal(v)<<endl;
    cout<<rangeVal(v)<<endl;
    

    return 0;
}