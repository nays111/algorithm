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

// int main(){
//     cin.tie(0);
//     cout.tie(0);
//     ios::sync_with_stdio(false);
//     string str;
//     cin>>str;
//     stack<char> op;
//     //스택에는 연산자와 (,) 만 들어갈 수 있음
//     for(int i=0;i<str.size();i++){
//         if(str[i]=='+'|| str[i]=='-' || str[i]=='/' || str[i]=='*'){
//             /**
//              * <연산자를 만났을 경우>
//              * 만약, stack의 가장 top 연산자가 *, /인데 그 +,-가 들어오려고 한다면,
//              * 먼저 stack의 있는 연산자를 모두 출력하고 삽입(?)
//              * 
//              * 만약, stack이 비었거나, stack의 바로 이전 부분이 '(' 면 삽입
//              * 
//              * 
//              * */
//             if(op.empty() || op.top()=='('){
//                op.push(str[i]); 
//             }else if(str[i]=='+' || str[i]=='-'){
//                 while(!op.empty()){
//                     if(op.top()!='('){
//                         cout<<op.top();
//                     }
//                     op.pop();
//                 }
//                 op.push(str[i]);
//             }else if(str[i]=='*' || str[i]=='/'){
//                 op.push(str[i]);
//             }
            
//         }else if(str[i]=='('){
//             /**
//              * <열기 괄호를 만났을 경우>
//              * stack에 push 외에 별다른 거는 없을 거같음,,,
//              * */
//             op.push(str[i]);
//         }
//         else if(str[i]==')'){
//             /**
//              * <닫기 괄호를 만났을 경우> 
//              * stack의 top이 '(' 일때까지 연산자들을 출력하고 pop해줌
//              * stack의 top이 '(' 이 되면 '('도 pop
//              * */
//             while(op.top()!='(' && !op.empty()){
//                 cout<<op.top();
//                 op.pop();
//             }
//             if(!op.empty()){
//                 op.pop();
//             }
            
//         }else{
//             /**
//              * <알파벳을 만났을 경우>
//              * 스택에는 연산자만 push하므로 알파벳은 순서대로 출력
//              * */
//             cout<<str[i];
//         }

//     }
//     while(!op.empty()){
//         cout<<op.top();
//         op.pop();
//     }

//     return 0;
// }

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    string str;
    cin>>str;
    stack<char> op;
    for(int i=0;i<str.size();i++){
        if(str[i]=='('){//여는 괄호인 경우 - ok
            op.push(str[i]);
        }else if(str[i]==')'){//닫는 괄호인 경우 - ok
            while(op.top()!='(' && !op.empty()){
                cout<<op.top();
                op.pop();
            }
            op.pop(); //'('도 pop해준다.

        }
        //스택은 우선순위가 낮으면 밑에 깔려야함 (높은게 위에 가도록)
        else if(str[i]=='+' || str[i]=='-'){ //우선순위가 낮은 연산자인 경우
            if(op.empty() || op.top()=='('){
                op.push(str[i]);
            }else{
                while(!op.empty() && op.top()!='('){
                    cout<<op.top();
                    op.pop();
                }
                op.push(str[i]);
            }
        }else if(str[i]=='*' || str[i]=='/'){//우선순위가 높은 연산자인 경우
            if(op.empty() || op.top()=='('){
                op.push(str[i]);
            }else{
                while(!op.empty() && (op.top()=='*' || op.top()=='/')){
                    cout<<op.top();
                    op.pop();
                }
                op.push(str[i]);
            }
        }else{//알파벳인 경우 - ok
            cout<<str[i];
        }
    }
    while(!op.empty()){
        cout<<op.top();
        op.pop();
    }



    return 0;
}