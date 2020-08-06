#include <iostream>

using namespace std;

int main(){
	int a[11], b[11], A = 0, B = 0, i = 0;
	char lastWin = 'D';
	
	for(i = 1; i <= 10; i++)
		scanf("%d", &a[i]);
	for(i = 1; i <= 10; i++)
		scanf("%d", &b[i]);
		
	for(i = 1; i <= 10; i++){
		if(a[i] > b[i]){
			A += 3;
			lastWin = 'A';
		}
		else if(a[i] < b[i]){
			B += 3;
			lastWin = 'B';
		}
		else{
			A++;
			B++;
		}
	}
	
	printf("%d %d\n", A, B);
	if(A == B){
		if(lastWin == 'D'){
			printf("D");
		}
		else{
			printf("%c", lastWin);
		}
	}
	else if(A > B){
		printf("A");
	}
	else if(B > A){
		printf("B");
	}
	
}

