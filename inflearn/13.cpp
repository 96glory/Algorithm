#include <iostream>

using namespace std;

int main(){
	char input[101];
	int cnt[10] = {0, };
	int max = -1, maxIndex = -1;
	
	scanf("%s", &input);
	
	for(int i = 0; input[i] != '\0'; i++){
		cnt[(int)(input[i] - '0')]++;
	}
	
	for(int i = 0; i < 10; i++){
		if(max < cnt[i]){
			maxIndex = i;
			max = cnt[i];
		}
		else if(max == cnt[i] && maxIndex < i){
			maxIndex = i;
		}
	}
	
	printf("%d", maxIndex);
}
