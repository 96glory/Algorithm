#include <iostream>

using namespace std;

int main(){
	char c[101];
	char answer[101];
	int index = 0;
	
	// scanf�� ������ �Է¹��� ���Ѵ�. ���� gets ���. 
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

