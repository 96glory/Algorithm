#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> prices) {
    int i, j, price_size = prices.size();
    vector<int> answer;

    for(i = 0; i < price_size - 1; i++){
        for(j = i + 1; j < price_size; j++){
            if(prices[i] > prices[j]){
                answer.push_back(j - i);
                break;
            }
        }
        if(answer.size() != i + 1){
            answer.push_back(j - i - 1);
        }
    }
    answer.push_back(0);

    return answer;
}
