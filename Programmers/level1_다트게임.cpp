#include <string>
#include <cmath>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int index = 0;
    int score = 0;
    int prev = 0;
    for(int i=0;i<dartResult.length();i++){
        //숫자인 경우 처리
        if(dartResult[i]>='0'&& dartResult[i]<='9'){ //1~9가 나왔을 경우
           //이전 기회에서의 점수를 담은 변수
             prev = score; //한바퀴 돌고나서 점수인것을 이전 점수에 담아 놈는다
            if(dartResult[i+1]=='0'){ //만약 0이 나온다면 점수가 10인 경우이다.
                score = 10;
                i++; //숫자 건져냈으니깐 전진
            }else{
                score=dartResult[i]-'0'; //문자열 숫자로 바꾸기
            }
            //알파벳인 경우 처리
        }else if(dartResult[i]=='S'|| dartResult[i]=='D'||dartResult[i]=='T'){
            if(dartResult[i]=='S'){
                //1제곱이므로 굳이 처리 안해도될듯
            }else if(dartResult[i]=='D'){
                //점수에 제곱해줘야함
                //아까 score에 저장해둔거에 제곱
                score = pow(score,2);
            }else if(dartResult[i]=='T'){
                score = pow(score,3); //이번엔 세제곱
            //이 다음에 기호가 나타난다면 그 기호에 따라서 점수가 변하게 됨
            //기호 처리
            }
            if(dartResult[i+1]=='*'){
                //옵션은 보너스 다음에 나오는 선택사항이므로 i+1로 처리
                //지금까지의 점수를 기록해논 건 score
                answer-=prev;//이전 점수도 두배하니깐 일단 빼놓고 두배하고 다시 더할거다
                prev=prev*2; 
                score = score*2;//현재 값도 두 배함
                answer+=prev; //이전값의 두 배한 값을 다시 넣어줌
                i++;
            }else if(dartResult[i+1]=='#'){
                //#이 나올 경우 곱하기 -1
                score = score*-1;
                //S기준에서 지금 처리하고 있는데 한칸 더 #까지 왔으니깐
                i++;
            }
            answer +=score;
        }
    }
    return answer;
}