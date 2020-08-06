#include <iostream>

using namespace std;

int main(){
	int N, A[101], B[101];
	scanf("%d", &N);
	
	for(int i = 1; i <= N; i++)
		scanf("%d", &A[i]);
	for(int i = 1; i <= N; i++)
		scanf("%d", &B[i]);
		
	for(int i = 1; i <= N; i++){
		if(A[i] == B[i]){
			printf("D\n");
		}
		else if((A[i] == 1 && B[i] == 3) || (A[i] == 2 && B[i] == 1) || (A[i] == 3 && B[i] == 2)){
			printf("A\n");
		}
		else{
			printf("B\n");
		}
	}
}

//		1 > 3
//		1 < 2
//		2 < 3
