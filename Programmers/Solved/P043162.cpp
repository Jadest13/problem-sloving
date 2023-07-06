#include <string>
#include <vector>
#include <queue>

#define MAX 201

using namespace std;

int visit[MAX];

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<int> V[MAX];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i==j) continue;
            if(computers[i][j]) {
                V[i].push_back(j);
                V[j].push_back(i);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(visit[i]) continue;
        
        queue<int> Q;
        Q.push(i);
        visit[i] = 1;
        while(!Q.empty()) {
            int p = Q.front();
            Q.pop();
            
            for(auto a : V[p]) {
                if(visit[a]) continue;
                
                Q.push(a);
                visit[a] = 1;
            }
        }
        answer++;
    }
    return answer;
}