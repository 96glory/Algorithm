#include <bits/stdc++.h>
using namespace std;

bool check(vector<vector<int>> baseball, int cmp){
    for(int i = 0; i < baseball.size(); i++){
        int S = 0, B = 0, temp = baseball[i][0];

        if((cmp / 100) == (temp / 100))             S++;
        if(((cmp / 10) % 10) == ((temp / 10) % 10)) S++;
        if((cmp % 10) == (temp % 10))               S++;
        if((temp / 100) == ((cmp / 10) % 10) || (temp / 100) == (cmp % 10))         B++;
        if(((temp / 10) % 10) == (cmp / 100) || ((temp / 10) % 10) == (cmp % 10))   B++;
        if((temp % 10) == (cmp / 100) || (temp % 10) == ((cmp / 10) % 10))          B++;

        if(S != baseball[i][1] || B != baseball[i][2])  return false;
    }
    return true;
}

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            for(int k = 1; k <= 9; k++){
                if(i == j || j == k || k == i)  continue;
                int cmp = 100 * i + 10 * j + k;
                if(check(baseball, cmp))  answer++;
            }
        }
    }
    return answer;
}
