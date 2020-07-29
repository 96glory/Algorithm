#include <bits/stdc++.h>
using namespace std;

queue<int> q;
int visit[200], answer = 1;

int solution(int n, vector<vector<int>> computers) {    
    q.push(0);
    visit[0] = answer;
    while(-1){
        if(q.empty()){
            for(int i = 0; i < n; i++){
                if(visit[i] == 0){
                    q.push(i);
                    visit[i] = ++answer;
                    break;
                }
            }
            if(q.empty())   return answer;
        }
        
        int temp = q.front();
        q.pop();
        
        for(int i = 0; i < n; i++){
            if(i == temp) continue;
            else if(computers[i][temp] == 1 && visit[i] == 0){
                q.push(i);
                visit[i] = answer;
            }
        }
    }
}
