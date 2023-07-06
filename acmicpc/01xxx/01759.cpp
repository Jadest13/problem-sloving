#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int L, C;
char c;
vector<char> V;
vector<char> M = {'a', 'e', 'i', 'o', 'u'};
vector<string> R;

void F(int n, int i, int m, int j, string s) {
  if(i > C) return;

  if(n == L) {
    if(m < 1 || j < 2) {
      return;
    }

    cout << s << "\n";
    return;
  }

  if(find(M.begin(), M.end(), V[i]) != M.end()) {
    F(n+1, i+1, m+1, j, s+V[i]);
  } else {
    F(n+1, i+1, m, j+1, s+V[i]);
  }
  F(n, i+1, m, j, s);
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> L >> C;
  for(int i = 0; i < C; i++) {
    cin >> c;
    V.push_back(c);
  }
  sort(V.begin(), V.end());

  F(0, 0, 0, 0, "");

  return 0;
}