#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
char arr[15];
char result[15];

void dfs(int depth, int index){
	if(depth > N)	return;
	else if(depth == N){
		for(int i = 0; i < N; i++)
			cout << result[i];
		cout << '\n';
		return;
	}
	
	for(int i = index + 1; i < M; i++){
		result[depth] = arr[i];
		dfs(depth + 1, i);
	}
}

int main(){
	cin >> N >> M;
	for(int i = 0; i < M; i++)
		cin >> arr[i];
		
	sort(arr, arr + M);
	
	dfs(0, -1);
	
}

