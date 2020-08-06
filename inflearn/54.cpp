#include <iostream>
#include <stack>

using namespace std;

int main(){
	char arr[31];
	scanf("%s", &arr);
	stack<int> s;
	for(int i = 0; arr[i] != '\0'; i++){
		if(arr[i] == '('){
			s.push(1);
		}
		else if(s.empty() && arr[i] == ')'){
			printf("NO");
			return 0;
		}
		else	s.pop();
	}
	if(s.empty())	printf("YES");
	else			printf("NO");
	
}

