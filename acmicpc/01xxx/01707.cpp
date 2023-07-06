#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int K, V, E;
int u, v;
vector<int> Ev[20001];
int Visit[20001];
int check;


void F(int n, int c) {
  Visit[n] = c;

  for(auto a : Ev[n]) {
    if(Visit[a] == c) {
      check = 0;
      return;
    }

    if(Visit[a] == 0) {
      F(a, -c);
    }
  }
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> K;

  while(K--) {
    memset(Visit, 0, sizeof(Visit));
    for(int i = 0; i <= 20000; i++) {
      Ev[i].clear();
    }
    check = 1;

    cin >> V >> E;
    for(int i = 0; i < E; i++) {
      cin >> u >> v;
      Ev[u].push_back(v);
      Ev[v].push_back(u);
    }
    
    for(int i = 1; i <= V; i++) {
      if(!check) {
        break;
      }

      if(!Visit[i]) {
        F(i, 1);
      }
    }

    if(check) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}