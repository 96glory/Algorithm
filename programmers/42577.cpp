#include <bits/stdc++.h>
using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    
    for(int i = 1; i < phone_book.size(); i++){
        string temp = phone_book[i].substr(0, phone_book[i - 1].length());
        if(temp == phone_book[i - 1])
            return false;
    }
    return true;
}
