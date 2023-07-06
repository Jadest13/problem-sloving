#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> m;
string S;
int N, M;
int R;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    cin >> S;
    m.insert({S, 1});
  }

  for(int i = 0; i < M; i++) {
    cin >> S;
    if(m.find(S) == m.end()) {
      m.insert({S, 1});
    } else {
      m.find(S)->second += 1;
      R++;
    }
  }

  cout << R << endl;
  for(auto iter:m) {
    if(iter.second == 2) {
      cout << iter.first << endl;
    }
  }

  return 0;
}