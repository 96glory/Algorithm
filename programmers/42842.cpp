#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    for(int i = 1; i <= yellow; i++){
        if(yellow % i == 0){
            int yellowWidth = max(i, yellow / i);
            int yellowHeight = min(i, yellow / i);

            if(brown ==  (yellowWidth + 2) * 2 + (yellowHeight + 2) * 2 - 4){
                answer.push_back(yellowWidth + 2);
                answer.push_back(yellowHeight + 2);
                break;
            }
        }
    }

    return answer;
}
