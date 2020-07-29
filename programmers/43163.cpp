#include <bits/stdc++.h>
using namespace std;

bool chk1diff(string a, string b){
    int cnt = 0;
    for(int i = 0; i < a.length(); i++){
        if(a[i] != b[i]) cnt++;
    }
    if(cnt == 1)    return true;
    return false;
}

int answer = 0, visit[50];
queue< pair<string, int> > q;

int solution(string begin, string target, vector<string> words) {
    q.push(make_pair(begin, 0));
    while(!q.empty()){
        string temp = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(temp == target){
            return cnt;
        }
        
        for(int i = 0; i < words.size(); i++){
            if(visit[i] != 0) continue;
            else{
                if(chk1diff(temp, words[i])){
                    visit[i] = 1;
                    q.push(make_pair(words[i], cnt + 1));
                }
            }
        }
    }
    return 0;
}
