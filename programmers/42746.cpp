#include <bits/stdc++.h>
using namespace std;

bool compare(string a, string b){
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;

    for(int i = 0 ; i < numbers.size(); i++){
        v.push_back(to_string(numbers[i]));
    }
    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < v.size(); i++){
        if(answer.empty() && v[i] == "0"){
            answer = "0";
            break;
        }
        answer.append(v[i]);
    }
    return answer;
}
