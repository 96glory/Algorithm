#include <iostream>
using namespace std;

int N, M, answer;
bool arr[52][52];
bool v[52][52];

void dfs(int a, int b){
	v[a][b] = true;
	if(arr[a - 1][b] && !v[a - 1][b])	dfs(a - 1, b);
	if(arr[a + 1][b] && !v[a + 1][b])	dfs(a + 1, b);
	if(arr[a][b - 1] && !v[a][b - 1])	dfs(a, b - 1);
	if(arr[a][b + 1] && !v[a][b + 1])	dfs(a, b + 1);
	
	if(arr[a + 1][b + 1] && !v[a + 1][b + 1])	dfs(a + 1, b + 1);
	if(arr[a - 1][b + 1] && !v[a - 1][b + 1])	dfs(a - 1, b + 1);
	if(arr[a + 1][b - 1] && !v[a + 1][b - 1])	dfs(a + 1, b - 1);
	if(arr[a - 1][b - 1] && !v[a - 1][b - 1])	dfs(a - 1, b - 1);
}

void clear(){
	answer = 0;
	for(int i = 0; i < 52; i++){
		for(int j = 0; j < 52; j++){
			arr[i][j] = false;
			v[i][j] = false;
		}
	}
}

int main(){
	while(-1){
		clear();
		cin >> N >> M;
		if(N == 0 && M == 0)	break;
		
		for(int i = 1; i <= M; i++){
			for(int j = 1; j <= N; j++){
				cin >> arr[i][j];
			}
		}
		
		for(int i = 1; i <= M; i++){
			for(int j = 1; j <= N; j++){
				if(arr[i][j] && !v[i][j]){
					dfs(i, j);
					answer++;
				}
			}
		}
		
		cout << answer << endl;
	}
}

