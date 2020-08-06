#include <bits/stdc++.h>
using namespace std;

vector<int> nums;
int answer = 0, tar;

void dfs(int level, int result){
    if(level == nums.size()){
        if(result == tar){
            answer++;
        }
    }
    else{
        dfs(level + 1, result + nums[level]);
        dfs(level + 1, result - nums[level]);
    }
}

int solution(vector<int> numbers, int target) {
    tar = target;
    nums = numbers;
    
    dfs(0, 0);
    return answer;
}
