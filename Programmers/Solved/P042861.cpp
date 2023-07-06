#include <bits/stdc++.h>

#define MAX 101

using namespace std;

typedef struct {
    int u, v, w;
} Edge;

int P[MAX];

int find_node(int u) {
    if(P[u] == u) return P[u];
    else return P[u] = find_node(P[u]);
}

void union_node(int u, int v) {
    u = find_node(u);
    v = find_node(v);
    if(u != v) P[v] = P[u];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<Edge> V;
    for(int i = 0; i < n; i++) {
        P[i] = i;
    }
    for(auto a : costs) {
        V.push_back({a[0], a[1], a[2]});
    }
    sort(V.begin(), V.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });
    
    for(auto a : V) {
        if(find_node(a.u) == find_node(a.v)) continue;
        union_node(a.u, a.v);
        answer += a.w;
    }
    
    return answer;
}