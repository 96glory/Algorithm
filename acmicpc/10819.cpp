#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int answer = -1000000000;

int main(){
	int N;
	scanf("%d", &N);
	vector<int> arr(N);
	for(int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	sort(arr.begin(), arr.end());
	do{
		int sum = 0;
		for(int i = 0; i < N - 1; i++){
			sum += abs(arr[i] - arr[i + 1]);
		}
		
		answer = max(sum, answer);
		
	}while(next_permutation(arr.begin(), arr.end()));

	printf("%d", answer);
}

