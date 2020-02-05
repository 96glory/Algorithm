#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> arr(20);
vector<int> emp(20, 0);
vector<int> alll(20);
int index = 0;

void add(int ele){
	if(find(arr.begin(), arr.end(), ele) == arr.end()){
		arr[index] = ele;
		index++;
	}
}
void remove(int ele){
	for(int i = 0; i <= index; i++){
		if(arr[i] == ele){
			for(int j = i; j <= index; j++)
				arr[j] = arr[j + 1];
			index--;
			break;
		}
	}
}
void check(int ele){
	if(find(arr.begin(), arr.end(), ele) == arr.end())
		printf("0\n");
	else
		printf("1\n");
}
void toggle(int ele){
	if(find(arr.begin(), arr.end(), ele) == arr.end()){
		arr[index] = ele;
		index++;
	}
	else{
		for(int i = 0; i <= index; i++){
			if(arr[i] == ele){
				for(int j = i; j <= index; j++)
					arr[j] = arr[j + 1];
				index--;
				break;
			}
		}
	}
}
void all(int ele){
	arr = alll;
	index = 19;
}
void empty(int ele){
	arr = emp;
	index = 0;
}
int main(){
	for(int i = 0; i < 20; i++)
		alll[i] = i + 1;
	int N;
	cin >> N;
	for(int i = 0; i < N; i++){
		string inst;
		int ele;
		
		cin >> inst;
		if(inst != "all" && inst != "empty")	cin >> ele;
		
		if(inst == "add")			add(ele);
		else if(inst == "remove")	remove(ele);
		else if(inst == "check")	check(ele);
		else if(inst == "toggle")	toggle(ele);
		else if(inst == "all")		all(ele);
		else if(inst == "empty")	empty(ele);
	}
}

