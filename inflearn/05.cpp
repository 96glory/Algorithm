#include <iostream>
#include <string.h>

using namespace std;

int main(){
	string input;
	cin >> input;
	const char * ch = input.c_str();	
	
	if(input.at(7) == '1'){
		cout << 120 - (int)((ch[0] - '0') * 10 + (ch[1] - '0')) << " " << "M";
	}
	else if(input.at(7) == '2'){
		cout << 120 - (int)((ch[0] - '0') * 10 + (ch[1] - '0')) << " " << "W";
	}
	else if(input.at(7) == '3'){
		cout << 20 - (int)((ch[0] - '0') * 10 + (ch[1] - '0')) << " " << "M";
	}
	else{
		cout << 20 - (int)((ch[0] - '0') * 10 + (ch[1] - '0')) << " " << "W";
	}
}

