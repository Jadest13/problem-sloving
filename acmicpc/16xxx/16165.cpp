#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int N, M;
string group, name;
string str;
int a;
map<string, vector<string>> G;
map<string, string> NM;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    cin >> group >> a;
    for(int i = 1; i <= a; i++) {
      cin >> name;
      G[group].push_back(name);
      NM[name] = group;
    }
    sort(G[group].begin(), G[group].end());
  }
  for(int i = 1; i <= M; i++) {
    cin >> str >> a;
    if(a) cout << NM[str] << "\n";
    else {
      for(auto a : G[str]) {
        cout << a << "\n";
      }
    }
  }

  return 0;
}