#include <iostream>

using namespace std;

const int MAX = 9;
int N, M;
int arr[MAX];

void find(int cnt, int index){
	if(cnt == M){
		for(int i = 0; i < M; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	
	for(int i = index; i <= N; i++){
		arr[cnt] = i;
		find(cnt + 1, i);
	}
}

int main(){
	cin >> N >> M;
	
	find(0, 1);
	return 0;
}

