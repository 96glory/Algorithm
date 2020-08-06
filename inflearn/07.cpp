#include <iostream>

using namespace std;

int main(){
	char c[101];
	char answer[101];
	int index = 0;
	
	// scanf는 공백을 입력받지 못한다. 따라서 gets 사용. 
	gets(c);
	
	for(int i = 0; c[i] != '\0'; i++){
		if('a' <= c[i] && c[i] <= 'z'){
			answer[index] = c[i];
			index++;
		}
		else if('A' <= c[i] && c[i] <= 'Z'){
			answer[index] = c[i] + 'a' - 'A';
			index++;
		}
	}
	answer[index] = '\0';
	printf("%s", answer);
}

