#include <iostream>

using namespace std;

int input[100];
int answer[100];

int main(){
	int n, cnt = 0;
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++)
		scanf("%d", &input[i]);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(answer[j] == 0 && cnt == input[i]){
				answer[j] = i;
				break;
			}
			if(answer[j] == 0){
				cnt++;
			}
		}
		cnt = 0;
	}
	
	for(int i = 1; i <= n; i++)
		printf("%d ", answer[i]);

	
}

