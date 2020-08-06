#include <iostream>

using namespace std;

int main(){
	char input[9];
	int c = 0, h = 0, i = 1;
	scanf("%s", &input);

	while(input[i] != 'H'){
		c *= 10;
		c += input[i] - '0';
		i++;
	}
	if(c == 0)	c = 1;
	i++;
	while(input[i] != '\0'){
		h *= 10;
		h += input[i] - '0';
		i++;
	}
	if(h == 0)	h = 1;	
	printf("%d", 12 * c + h);
}

