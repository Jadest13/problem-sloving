#include <bits/stdc++.h>

#define INF 1e9

using namespace std;

int DFS(string begin, string target, vector<string> words, int n, int bit) {
    //cout << n << ", " << begin << "\n";
    if(begin == target) return n;
    int ret = INF;
    for(int i = 0; i < words.size(); i++) {
        if(bit & (1<<i)) continue;
        int flag = 0;
        for(int j = 0; j < begin.size(); j++) {
            if(begin[j] != words[i][j]) {
                flag++;
            }
        }
        if(flag != 1) continue;
        
        ret = min(ret, DFS(words[i], target, words, n+1, bit | (1<<i)));
    }
    return ret;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    answer = DFS(begin, target, words, 0, 0);
    if(answer == INF) answer = 0;
    
    return answer;
}