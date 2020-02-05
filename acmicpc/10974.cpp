#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	vector<int> arr(N, 0);
	
	for(int i = 0; i < N; i++)
		arr[i] = i + 1;
		
	do{
		for(int i = 0; i < arr.size(); i++)
			printf("%d ", arr[i]);
		printf("\n");
	}while(next_permutation(arr.begin(), arr.end()));
	
}
