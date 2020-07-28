#include <bits/stdc++.h>
using namespace std;

int solution(string arrangement) {
    int answer = 0;
    stack<int> s;

    for(int i = 0; arrangement[i] != '\0'; i++){
        if(arrangement[i] == '(')   s.push(1);
        else if(arrangement[i] == ')'){
            s.pop();
            if(arrangement[i - 1] == '(')       answer += s.size();
            else if(arrangement[i - 1] == ')')  answer++;
        }
    }
    return answer;
}
