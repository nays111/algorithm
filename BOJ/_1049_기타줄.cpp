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
    int N,M;
    cin>>N>>M;
    int arr[M][2];
    int cheapestPackage=1001;
    int cheapestIndividual = 1001;
    for(int i=0;i<M;i++){
        cin>>arr[i][0];
        cin>>arr[i][1];
        if(arr[i][0]<cheapestPackage){
            cheapestPackage = arr[i][0]; //패키지상품 중 가장 싼거
        }
        if(arr[i][1]<cheapestIndividual){
            cheapestIndividual = arr[i][1]; //개별상품 중 가장 싼거
        }
    }
    //case는 3개
    //1) 낱개로만 구입한 경우
    int priceIndividual = cheapestIndividual*N;
    //2) 패키지로만 구입한 경우
    int pricePackage = cheapestPackage*((N/6)+1);
    //3) 혼합해서 구입한 경우
    int priceMix = cheapestPackage*(N/6)+cheapestIndividual*(N%6);
    cout<<min(priceIndividual,min(priceMix,pricePackage));
    
    return 0;
}