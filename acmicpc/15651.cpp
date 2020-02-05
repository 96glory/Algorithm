#include <iostream>

using namespace std;

const int MAX = 9;
int N, M;
int arr[MAX];

void find(int cnt){
	if(cnt == M){
		for(int i = 0; i < M; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	
	for(int i = 1; i <= N; i++){
		arr[cnt] = i;
		find(cnt + 1);
	}
}

int main(){
	cin >> N >> M;
	
	find(0);
	return 0;
}

