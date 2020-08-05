#include <bits/stdc++.h>
using namespace std;
 
int N, num, BIT;
string input;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    while(N--){
    	input.clear();
        cin >> input;
        
        if (input == "add"){
            cin >> num;
            BIT |= (1 << num);
        }
        else if (input == "remove"){
            cin >> num;
            BIT &= ~ (1 << num);
        }
        else if (input == "check"){
            cin >> num;
            if (BIT & (1 << num))	cout << 1 << '\n';
            else					cout << 0 << '\n';
        }
        else if (input == "toggle"){
            cin >> num;
            BIT ^= (1 << num);
        }
        else if (input == "all"){
            BIT = (1 << 21) - 1;
        }
        else if (input == "empty"){
            BIT = 0;
        }
    }
}

