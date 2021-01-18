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
// bool visit[1024];
// int arr[1024];
// void dfs(int index,int target){
//     visit[index]=true;
//     cout<<index;
//     int first = index*2;
//     int second = index*2 + 1;
//     if(target==first || target==second){
//         return;
//     }
//     dfs(first,target);
//     dfs(second,target);
//     return;
// }

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        vector<int> av;
        vector<int> bv;
        // dfs(1,a);
        // dfs(1,b);
        while(a>0){
            av.push_back(a);
            a=a/2;
        }
        while(b>0){
            bv.push_back(b);
            b=b/2;
        }
        vector<int> answer;
        for(int j=0;j<av.size();j++){
            for(int k=0;k<bv.size();k++){
                if(av[j]==bv[k]){
                    answer.push_back(av[j]);
                }
            }
        }
        sort(answer.begin(),answer.end());
        cout<<answer[answer.size()-1]*10<<'\n';
            
    }
    
    
    return 0;
}