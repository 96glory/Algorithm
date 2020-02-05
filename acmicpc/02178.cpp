#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int answer = 987654321;
int N, M;
bool arr[102][102];

void maze(int a, int b, int step, vector<vector<bool>> v){
	v[a][b] = true;
	
	if(step >= answer)	return;
	if(a == N && b == M){
		answer = min(answer, step);
		return;
	}
	
	if(arr[a + 1][b] && !v[a + 1][b])	maze(a + 1, b, step + 1, v);
	if(arr[a][b + 1] && !v[a][b + 1])	maze(a, b + 1, step + 1, v);
	if(arr[a - 1][b] && !v[a - 1][b])	maze(a - 1, b, step + 1, v);
	if(arr[a][b - 1] && !v[a][b - 1])	maze(a, b - 1, step + 1, v);
}

int main(){
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		string temp;
		cin >> temp;
		for(int j = M; j >= 1; j--){
			string set;
			set.append(temp, temp.length() - 1, 1);
			temp.pop_back();
			arr[i][j] = stoi(set);
		}
	}
	vector<vector<bool>> v(N + 2, vector<bool>(M + 2, false));
	maze(1, 1, 1, v);
	cout << answer;
}

