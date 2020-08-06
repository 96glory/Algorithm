#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int progresses_size = progresses.size();
    vector<int> answer;
    vector<int> endDay(progresses_size, 0);

    int day = 0, endJob = 0;
    while(endJob < progresses_size){
        day++;
        for(int i = 0; i < progresses_size; i++){
            if(progresses[i] >= 100)    continue;
            progresses[i] += speeds[i];
            if(progresses[i] >= 100){
                endDay[i] = day;
                endJob++;
            }
        }
    }

    int temp = endDay[0], cnt = 1;
    for(int i = 1; i < progresses_size; i++){
        if(temp < endDay[i]){
            temp = endDay[i];
            answer.push_back(cnt);
            cnt = 0;
        }
        cnt++;
    }
    answer.push_back(cnt);
    return answer;
}
