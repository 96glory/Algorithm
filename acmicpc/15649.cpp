#include <iostream>
#include <vector>

using namespace std;

const int MAX = 9;
int N, M;
int arr[MAX];
bool v[MAX];

void find(int cnt){
	if(cnt == M){
		for(int i = 0; i < M; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	
	for(int i = 1; i <= N; i++){
		if(!v[i]){
			v[i] = true;
			arr[cnt] = i;
			find(cnt + 1);
			v[i] = false;
		}
	}
}

int main(){
	cin >> N >> M;
	
	find(0);
	return 0;
}

