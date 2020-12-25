#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

//1-2-4 , 5-4-4
int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end(),greater<>());
    for(int i=0;i<A.size();i++){
        answer += A[i] * B[i];
    }

    return answer;
}