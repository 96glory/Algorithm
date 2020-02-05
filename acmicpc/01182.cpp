#include <iostream>

using namespace std;

int N, S, answer;
int arr[20];

void find(int index, int sum){
	sum += arr[index];
	if(index >= N)	return;
	if(sum == S)	answer++;
	
	find(index + 1, sum - arr[index]);
	find(index + 1, sum);
}

int main(){
	cin >> N >> S;
	for(int i = 0; i < N; i++)
		cin >> arr[i];
		
	find(0, 0);
	cout << answer;
}
