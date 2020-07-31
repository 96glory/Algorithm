#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> q;
    for(auto o : operations){
        if(o[0] == 'I'){
            string temp = o.substr(2);
            q.push_back(stoi(temp));
        }
        else if(!q.empty() && o == "D 1"){
            if(q.size() != 1)
                sort(q.begin(), q.end());
            q.pop_back();
        }
        else if(!q.empty() && o == "D -1"){
            if(q.size() != 1)
                sort(q.rbegin(), q.rend());
            q.pop_back();
        }
    }
    
    sort(q.begin(), q.end());
    vector<int> answer;
    if(q.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(q[q.size() - 1]);
        answer.push_back(q[0]);
    }
    return answer;
}
