#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    vector<int> temp;

    for(int i = heights.size() - 1; i >= 0; i--) {
        for(int j = i - 1; j >= 0; j--) {
            if(heights[j] > heights[i]){
                temp.push_back(j + 1);
                break;
            }
            if(j == 0) temp.push_back(0);
        }
        if(i == 0) temp.push_back(0);
    }

    for(int i = temp.size() - 1; i >= 0; i--){
        answer.push_back(temp[i]);
    }
    return answer;
}
