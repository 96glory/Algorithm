#include <iostream>

using namespace std;

int main(){
	int N, M, answer = -1, temp = 0, sensor;
	scanf("%d %d", &N, &M);
	
	for(int i = 0; i < N; i++){
		scanf("%d", &sensor);
		
		if(sensor > M)	temp++;
		else			temp = 0;
		
		if(answer < temp)
			answer = temp;
	}
	
	if(answer != -1)	printf("%d", answer);
	else				printf("-1");
}
