#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 9;
int N, M;
int arr[MAX];
int obj[MAX];

void find(int cnt){
	if(cnt == M){
		for(int i = 0; i < M; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	
	for(int i = 1; i <= N; i++){
		arr[cnt] = obj[i];
		find(cnt + 1);
	}
}

int main(){
	cin >> N >> M;
	for(int i = 1; i <= N; i++)
		cin >> obj[i];
		
	sort(obj + 1, obj + 1 + N);
	find(0);
	return 0;
}

