#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> G;
    map<string, vector<pair<int, int>>> P;
    for(int i = 0; i < genres.size(); i++) {
        G[genres[i]] += plays[i];
        P[genres[i]].push_back({i, plays[i]});
    }
    vector<pair<string, int>> V(G.begin(), G.end());
    sort(V.begin(), V.end(), [](pair<string, int> a, pair<string, int> b) {
        return a.second > b.second;
    });
    for(auto a : V) {
        sort(P[a.first].begin(), P[a.first].end(), [](pair<int, int> a, pair<int, int> b) {
            if(a.second == b.second) return a.first < b.first;
            else return a.second > b.second;
        });
        for(int i = 0; i < 2 && i < P[a.first].size(); i++) {
            answer.push_back(P[a.first][i].first);
        }
    }

    return answer;
}