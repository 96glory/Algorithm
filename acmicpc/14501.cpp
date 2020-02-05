#include <iostream>
#include <cmath>

using namespace std;

int N;
int arr[2][16];
int answer = -1000000000;

void find(int index, int sum){
	int temp = index;
	sum += arr[1][index];
	index += arr[0][index];
	
	
	if(index > N + 1)	return;
	answer = max(answer, sum);
		
	for(int i = index; i <= N; i++)
		find(i, sum);
}


int main(){
	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> arr[0][i] >> arr[1][i];
		
	for(int i = 1; i <= N; i++)
		find(i, 0);
	
	cout << answer;
}
