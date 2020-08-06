#include <bits/stdc++.h>
using namespace std;

struct Music{
    int index;
    int play;
    Music(int b, int c){
        index = b;
        play = c;
    }
    bool operator < (const Music & b) const {
        if(play == b.play){
            return index < b.index;
        }
        return play > b.play;
    }
};

bool cmp(pair<string, int> a, pair<string , int> b){
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    int numMusic = genres.size();

    map<string, int> sumGenre;
    map<string, vector<Music>> groupByGenre;

    for(int i = 0; i < numMusic; i++){
        sumGenre[genres[i]] += plays[i];
        groupByGenre[genres[i]].push_back(Music(i, plays[i]));
    }

    vector<pair<string, int>> v;
    for(auto & k : sumGenre){
        v.push_back(make_pair(k.first, k.second));
    }
    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < v.size(); i++){
        string target = v[i].first;
        sort(groupByGenre[target].begin(), groupByGenre[target].end());

        for(int i = 0; i < min(2, (int) groupByGenre[target].size()); i++){
            answer.push_back(groupByGenre[target][i].index);
        }
    }

    return answer;
}
