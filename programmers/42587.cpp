#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    queue< pair<int, int> > q;
    for(int i = 0; i < priorities.size(); i++){
        q.push(make_pair(i, priorities[i]));
    }

    while(-1){
        bool flag = true;
        int idx = q.front().first;
        int pri = q.front().second;
        q.pop();

        int size = q.size();
        for(int i = 0; i < size; i++){
            int _idx = q.front().first;
            int _pri = q.front().second;
            q.pop();

            if(pri < _pri){
                flag = false;
            }
            q.push(make_pair(_idx, _pri));
        }

        if(flag == false){
            q.push(make_pair(idx, pri));
        }
        else{
            answer++;
            if(idx == location){
                return answer;
            }
        }
    }
}
