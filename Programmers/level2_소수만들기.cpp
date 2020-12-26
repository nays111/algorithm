#include <vector>
#include <iostream>
using namespace std;
//1+2+3 , 1+2+4, 1+3+4, 2+3+4
//1+2+7 , 1+2+6, 1+2+4, 2+7+6, 2+7+4, 7+6+4
//nC3
//(n)(n-1)(n-2)/6 => 4 3 2/6
bool isPrime(int n){
    if(n==0 || n==1){
        return false;
    }
    for(int i=2;i<n-1;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int solution(vector<int> nums) {
    int answer = 0;
    int sum = 0;
    for(int i=0;i<nums.size()-2;i++){
        for(int j=i+1;j<nums.size()-1;j++){
            for(int k=j+1;k<nums.size();k++){
                sum = nums[i]+nums[j]+nums[k];
                if(isPrime(sum)==true){
                    answer++;
                }
            }
        }
    }

    return answer;
}