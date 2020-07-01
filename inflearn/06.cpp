#include <iostream>

using namespace std;

int main(){
	int answer = 0, cnt = 0;
	char c[50];
	scanf("%s", &c);
	
	// for(i = 0; a[i] != '\0'; i++) 로 표현 가능. 
	// 위와 같이 하면 break 생략 가능 
	for(int i = 0; i < 50; i++){
		if(c[i] == '\0'){
			break;
		}
	
		else if('0' <= c[i] && c[i] <= '9'){
			answer *= 10;
			answer += (int) (c[i] - '0');
		}
	}
	
	for(int i = 1; i <= answer; i++){
		if(answer % i == 0){
			cnt++;
		}
	}
	
	printf("%d\n%d", answer, cnt);
}

