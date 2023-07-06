#include <bits/stdc++.h>

using namespace std;
using PII = pair<int, int>;

int DFS(int k, vector<vector<int>> dungeons, int bit, int a) {
    int ret = a;
    for(int i = 0; i < dungeons.size(); i++) {
        if(bit & (1 << i)) continue;
        if(k >= dungeons[i][0]) {
            ret = max(ret, DFS(k - dungeons[i][1], dungeons, bit | (1<<i), a+1));
        }
    }
    return ret;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    answer = DFS(k, dungeons, 0, 0);

    return answer;
}