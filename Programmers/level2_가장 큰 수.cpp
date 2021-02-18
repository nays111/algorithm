#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(string a,string b ){
    if(a+b > b+a){
        return true;
    }else{
        return false;
    }
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> temp;
    sort(numbers.begin(),numbers.end(),greater<>());
    for(int i=0;i<numbers.size();i++){
        temp.push_back(to_string(numbers[i]));
    }
    sort(temp.begin(),temp.end(),compare);
    if(temp[0]=="0"){
        return "0";
    }
    for(int i=0;i<temp.size();i++){
        answer=answer+temp[i];
    }
    return answer;
}