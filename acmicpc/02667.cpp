#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N;
bool arr[27][27];
bool v[27][27];
vector<int> answer;

int dfs(int a, int b){
	int sum = 1;
	v[a][b] = true;
	if(arr[a - 1][b] && !v[a - 1][b])	sum += dfs(a - 1, b);
	if(arr[a + 1][b] && !v[a + 1][b])	sum += dfs(a + 1, b);
	if(arr[a][b - 1] && !v[a][b - 1])	sum += dfs(a, b - 1);
	if(arr[a][b + 1] && !v[a][b + 1])	sum += dfs(a, b + 1);
	return sum;
}

int main(){
	cin >> N;
	for(int i = 1; i <= N; i++){
		string temp;
		cin >> temp;
		for(int j = 1; j <= N; j++){
			string cmp;
			cmp.assign(temp, j - 1, 1);
			if(cmp == "1")	arr[i][j] = true;
		}
	}
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			if(arr[i][j] && !v[i][j]){
				int ans = dfs(i, j);
				answer.push_back(ans);
			}
		}
	}
	sort(answer.begin(), answer.end());
	cout << answer.size() << '\n';
	for(int i = 0; i < answer.size(); i++){
		cout << answer[i] << '\n';
	}
}

