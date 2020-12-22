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
    int N,C;
    cin>>N>>C;
    vector<pair<int,int>> v(N,{0,0});//사진 번호, 액자에 걸려있던 시간
    int recommend[C];//각각 추천 몇번받았는지
    for(int i=0;i<C;i++){
        int num;
        cin>>num;
        recommend[num]++;
        bool replace = true;//바꿔줘야할지말지 판단하기 위해
        for(int j=0;j<N;j++){
            if(v[j].second==0){
                //만약 액자에 아무사진도 안걸려있다면
                //i번재 사진에 num번 사진 넣는다.
                v[j].second = num;
                v[j].first = i;
                //바꿔줄 필요 없음
                replace = false;
                break;
            }else if(v[j].second == num){
                //4.이미 같은 사진이 걸려있다면
                //추천수를 증가시켜준다.
                //recommend[num++];-> 애초에 처음 증가시켜줘서 증가시킬 필요 없음
                //바꿔줄 필요 없음
                replace = false;
                break;
            }
        }
        if(replace){
            //바꿔줘야하는 경우
            //3. 비어있는 사진틀이 없는 경우에는 
            //현재까지 추천 받은 횟수가 가장 적은 학생의 사진을 삭제하고, 
            //그 자리에 새롭게 추천받은 학생의 사진을 게시한다. 
            //이때, 현재까지 추천 받은 횟수가 가장 적은 학생이 두 명 이상일 경우에는 
            //그러한 학생들 중 게시된 지 가장 오래된 사진을 삭제한다.
            //int minRecommend = recommend[v[0].first];
            //int longTime = v[0].second;
            int index = 0;
            for(int j=1;j<N;j++){
                if(recommend[v[j].second]==recommend[v[index].second]){
                    //만약 추천수가 같다면 가장 오래된(큰) 사진을 삭제
                    if(v[j].first < v[index].first){
                        
                        index = j; //몇번째 액자인지 메모
                    }
                }else if(recommend[v[j].second]<recommend[v[index].second]){
                    //추천수가 다르다면 추천수가 가장 적은 것을 제외
                    index = j; //액자 메모
                }
            }
            recommend[v[index].second] = 0; //제외된건 추천수 0으로 초기화
            v[index].first = i;
            v[index].second = num; //num 번 사진 액자에 넣고
            
        }
    }
    vector<int> printFor;
    for(int i=0;i<N;i++){
        printFor.push_back(v[i].second);
    }
    sort(printFor.begin(),printFor.end());
    for(int i=0;i<N;i++){
        cout<<printFor[i]<<" ";
    }

    return 0;
}



