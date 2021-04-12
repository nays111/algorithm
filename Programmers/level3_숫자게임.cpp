#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int pointerA = 0;
    int pointerB = 0;
    while(pointerB!=B.size()){
        //cout<<A[pointerA]<<" "<<B[pointerB]<<'\n';
        if(A[pointerA] < B[pointerB]){
            pointerA++;
            pointerB++;
            answer++;
        }else {
            pointerB++;
        }
    }
    return answer;
}