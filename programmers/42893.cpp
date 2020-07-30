#include <bits/stdc++.h>
using namespace std;

bool chkPrime(int a){
    if(a == 0 || a == 1)  return false;
    for(int i = 2; i <= sqrt(a); i++){
        if(a % i == 0)  return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0, size = numbers.size();
    map<int, int> m;
    sort(numbers.begin(), numbers.end());
    
    do{
        for(int i = 1; i <= size; i++){
            string _temp = numbers.substr(0, i);
            int temp = stoi(_temp);
            if(m[temp] == 0 && chkPrime(temp)){
                m[temp]++;
            }    
        }
    }while(next_permutation(numbers.begin(), numbers.end()));
    
    for(auto k : m){
        if(k.second != 0)
            answer++;
    }
    return answer;
}
