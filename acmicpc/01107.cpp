#include <bits/stdc++.h>
#define START 100
using namespace std;

int target, brokenNum, temp, answer;
vector<int> tmp(10, 0);
vector<int> live;
vector<int> cand(6, 0);

void dfs(int cnt, int tar){
	if(cnt == tar){
		temp = 0;
		for(int i = 0; i < cnt; i++){
			temp *= 10;
			temp += cand[i];
		}
		answer = min(answer, tar + abs(target - temp));
	}
	else{
		for(int i = 0; i < live.size(); i++){
			cand[cnt] = live[i];
			dfs(cnt + 1, tar);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> target >> brokenNum;
	for(int i = 0; i < brokenNum; i++){
		cin >> temp;
		tmp[temp] = 1;
	}
	for(int i = 0; i <= 9; i++){
		if(tmp[i] == 0)
			live.push_back(i);
	}
	
	answer = abs(target - START);
	
	for(int i = 1; i <= 6; i++){
		for(int j = 0; j < 6; j++){
			cand[j] = 0;
		}
		dfs(0, i);
	}
	
	cout << answer;
}

