#include <iostream>

using namespace std;

int cnt1[52], cnt2[52];

int main(){
	char input1[101], input2[101];
	scanf("%s", input1);
	scanf("%s", input2);
	
	for(int i = 0; input1[i] != '\0'; i++){
		if('A' <= input1[i] && input1[i] <= 'Z'){
			cnt1[(int)(input1[i] - 'A') + 26]++;
		}
		else{
			cnt1[(int)(input1[i] - 'a')]++;
		}
	}
	
	for(int i = 0; input2[i] != '\0'; i++){
		if('A' <= input2[i] && input2[i] <= 'Z'){
			cnt2[(int)(input2[i] - 'A') + 26]++;
		}
		else{
			cnt2[(int)(input2[i] - 'a')]++;
		}
	}
	
	int flag = 1;
	for(int i = 0; i < 52; i++){
		if(cnt1[i] != cnt2[i]){
			flag = 0;
			break;
		}
	}
	
	if(flag == 1)	printf("YES");
	else			printf("NO");
		
}

