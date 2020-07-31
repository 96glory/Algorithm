#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int> > pq;    
    for(auto s : scoville)  pq.push(s);

    while(-1){        
        int low1 = pq.top();
        pq.pop();
        if(low1 >= K)       return answer;
        if(pq.size() == 0)  return -1;

        int low2 = pq.top();
        pq.pop();

        pq.push(low1 + low2 * 2);
        answer++;
    }
}
