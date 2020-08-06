#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.rbegin(), citations.rend());
    for(auto c : citations){
        if(answer + 1 > c)  break;
        answer++;
    }
    return answer;
}
