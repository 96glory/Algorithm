#include <iostream>

using namespace std;

int output[50001];

int main(){
	int N, i = 0;	
	
	scanf("%d", &N);
	
	for(int i = 1; i <= 50000; i++){
		for(int j = i; j <= 50000; j += i){
			output[j]++;
		}
	}
	
	for(int i = 1; i <= N; i++){
		printf("%d ", output[i]);
	}
}
