#include <iostream>

using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++){
		int last, sum = 0, candidate;
		scanf("%d %d", &last, &candidate);
		
		for(int j = 1; j <= last; j++)
			sum += j;

		
		if(sum == candidate)	printf("YES\n");
		else					printf("NO\n");
	}
}

