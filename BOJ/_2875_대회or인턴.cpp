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
    int N,M,K;
    cin>>N>>M>>K;
    int teamCount=0;
    if(N/2>=M){
        teamCount = M; //만들어진 팀 개수
    }else{
        teamCount = N/2;//만들어진 팀 개수
    }
    //1 : 먼저 사람들을 다 짝지어두고 남은 사람을 인턴으로 보내기
    int remainCount = (N-(teamCount*2));
    remainCount += (M-teamCount);
    if(K>=remainCount){ 
        K-=remainCount;//아직 인턴갈 사람이 남은 경우
    }else{
        K=0; //인턴을 다 보냈는데도 짝못이룬 사람인 경우 (이 경우는 생각안해도됨)
    }
    //2 : 남은 사람을 다 보냈는데도 인턴 보낼 사람이 부족한 경우
    //  이제 만들어진 팀에서 사람들을 빼야댐
    //  그렇다면 무조건 팀 개수가 줄어든다.
    //2-1 : 만약 3단위로 보내야할 사람이 남아있으면 공정하게 여2남1 인턴 보내면 됨
    if(K%3==0){
        teamCount-=(K/3);
    }else{//2-2 : 만약 아니면 
        teamCount-=((K/3)+1);
    }
    cout<<teamCount;
    return 0;
}