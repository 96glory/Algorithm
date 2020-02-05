#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 9;
int N, M;
int obj[MAX];
int arr[MAX];

void find(int cnt, int index){
	if(cnt == M){
		for(int i = 0; i < M; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	
	for(int i = index; i <= N; i++){
		arr[cnt] = obj[i];
		find(cnt + 1, i);
	}
}

int main(){
	cin >> N >> M;
	for(int i = 1; i <= N; i++)
		cin >> obj[i];
		
	sort(obj + 1, obj + N + 1);
	find(0, 1);
	return 0;
}

