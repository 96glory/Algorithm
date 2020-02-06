#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool flag = false;

using namespace std;

int main(){
    int cnt;
    cin >> cnt;
    vector<string> result;
    
    for(int cases = 0; cases < cnt; cases++){
        int numOfPhone;
        cin >> numOfPhone;
        
        vector<string> list;
        for(int i = 0; i < numOfPhone; i++){
        	string temp;
        	cin >> temp;
        	list.push_back(temp);
		}
		
		sort(list.begin(), list.end());
        
        for(int i = 0; i < list.size() - 1; i++){
        	string temp;
			temp.assign(list[i + 1], 0, list[i].size());
			if(temp.compare(list[i]) == 0){
				flag = true;
				result.push_back("NO");
				break;
			}
		}
		
		if(flag == false){
			result.push_back("YES");
		}
        flag = false;
    }
    
    for(int i = 0; i < cnt; i++){
    	cout << result[i] << endl;
	}
}
