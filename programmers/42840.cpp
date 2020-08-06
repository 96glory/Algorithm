#include <bits/stdc++.h>
using namespace std;

vector<int> answer;
int score[4];
int std1[5] = {1, 2, 3, 4, 5};
int std2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
int std3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    for(int i = 0; i < answers.size(); i++){
        if(answers[i] == (std1[i % 5]))   score[1]++;
        if(answers[i] == (std2[i % 8]))   score[2]++;
        if(answers[i] == (std3[i % 10]))  score[3]++;
    }

    int max = *max_element(score + 1, score + 4);
    for(int i = 1; i <= 3; i++){
        if(max == score[i]) answer.push_back(i);
    }

    return answer;
}
