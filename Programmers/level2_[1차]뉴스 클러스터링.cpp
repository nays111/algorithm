#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    //대문자 변환
    transform(str1.begin(),str1.end(),str1.begin(),::toupper);
    transform(str2.begin(),str2.end(),str2.begin(),::toupper);
    
    //두개씩잘라서 임시 배열 v1,v2에 넣기
    vector<string> v1;
    vector<string> v2;
    for(int i=1;i<str1.size();i++){
        string temp;
        temp+=str1[i-1];
        temp+=str1[i];
        v1.push_back(temp);
    }
    for(int i=1;i<str2.size();i++){
        string temp;
        temp+=str2[i-1];
        temp+=str2[i];
        v2.push_back(temp);
    }
    
    //임시배열v1,v2에 있는 문자열이 알파벳으로만 이루었는지 확인
    //두개의 문자열이 모두 알파벳인것만 vv1,vv2로
    //어차피 임시배열에는 두글자의 문자열만 들어가있음, 그 두개 모두 대문자로 바뀌어있는 상태이므로 대문자 경우만 조사
    vector<string> vv1;
    vector<string> vv2;
    for(int i=0;i<v1.size();i++){
        string target = v1[i];
        if(target[0]>='A' && target[0]<='Z' && target[1]>='A' && target[1]<='Z'){
            vv1.push_back(target);
        }
    }
    for(int i=0;i<v2.size();i++){
        string target = v2[i];
        if(target[0]>='A' && target[0]<='Z' && target[1]>='A' && target[1]<='Z'){
            vv2.push_back(target);
        }
    }
    //set_intersection을 사용하기 위해서는 정렬해야함.
    sort(vv1.begin(),vv1.end());
    sort(vv2.begin(),vv2.end());
    int cnt = vv1.size() + vv2.size();
    //아예 부분집합들이 없을 경우
    if(cnt==0){
        return 65536;
    }
    //두 집합 개수의 합 =  합집합의 개수 - 교집합의 개수
    vector<string> inter(cnt);
    auto it = set_intersection(vv1.begin(),vv1.end(),vv2.begin(),vv2.end(),inter.begin());
    inter.erase(it,inter.end());
    int interCount = inter.size();
    int unionCount = cnt-interCount;
    
    answer = ((double)interCount/(double)unionCount)*65536;
    
        
    return answer;
}