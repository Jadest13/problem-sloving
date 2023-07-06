#include <string>
#include <vector>
#include <queue>

#define MAX 20001

using namespace std;

vector<int> V[MAX];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int Dijk[MAX];
    int mx = 0;
    for(int i = 1; i <= n; i++) {
        Dijk[i] = -1;
    }
    
    for(auto a : edge) {
        V[a[0]].push_back(a[1]);
        V[a[1]].push_back(a[0]);
    }
    
    queue<int> Q;
    Q.push(1);
    Dijk[1] = 0;
    while(!Q.empty()) {
        int p = Q.front();
        Q.pop();
        
        for(auto a : V[p]) {
            if(Dijk[a] == -1) {
                Q.push(a);
                Dijk[a] = Dijk[p]+1;
            } else {
                Dijk[a] = min(Dijk[a], Dijk[p]+1);
            }
            mx = max(mx, Dijk[a]);
        }
    }
    
    for(int i = 1; i <= n; i++) {
        if(Dijk[i] == mx) answer++;
    }
    
    return answer;
}