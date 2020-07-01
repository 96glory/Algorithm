#include <iostream>

using namespace std;

int main(){
	char arr[31];
	int cnt = 0, i = 0;	
	scanf("%s", &arr);	
	
	while(i <= 30 || arr[i] != '\0'){
		if(arr[i] == '\('){
			cnt++;
		}
		if(arr[i] == '\)'){
			if(cnt <= 0){
				printf("NO");
				return 0;
			}
			else{
				cnt--;
			}
		}
		i++;
	}
	
	if(cnt == 0){
		printf("YES");
	}
	else{
		printf("NO");
	}
	
}

