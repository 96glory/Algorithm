#include <bits/stdc++.h>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, onWeight = 0, waitingIndex = 0;
    queue< pair<int, int> > crossing;
    
    while(-1){
        int crossingNum = crossing.size();
        
        for(int i = 0; i < crossingNum; i++){
            int wei = crossing.front().first;
            int len = crossing.front().second;
            crossing.pop();
            
            if(len <= 1){
                onWeight -= wei;
                continue;
            }
            crossing.push(make_pair(wei, len - 1));
        }
        
        if(waitingIndex < truck_weights.size() && onWeight + truck_weights[waitingIndex] <= weight){
            crossing.push(make_pair(truck_weights[waitingIndex], bridge_length));
            onWeight += truck_weights[waitingIndex];
            waitingIndex++;
        }

        answer++;
        
        if(waitingIndex >= truck_weights.size() && crossing.empty())
            break;
    }    
    return answer;
}
