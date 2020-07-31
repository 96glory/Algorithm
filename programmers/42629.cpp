#include <bits/stdc++.h>
using namespace std;

struct Data{
    int date;
    int supply;
    Data(int a, int b): date(a), supply(b) {}
};

struct cmp{
    bool operator()(Data a, Data b){
        return a.supply < b.supply;
    }
};

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int current = stock;

    priority_queue<Data, vector<Data>, cmp> pq;
    queue<Data> q;

    for(int i = 0; i < dates.size(); i++)
        q.push(Data(dates[i], supplies[i]));

    while(current < k){
        while(!q.empty() && current >= q.front().date){
            pq.push(q.front());
            q.pop();
        }

        current += pq.top().supply;
        pq.pop();
        answer++;
    }

    return answer;
}
