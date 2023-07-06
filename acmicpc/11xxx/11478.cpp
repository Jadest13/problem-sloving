#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> m;
string S, tmp;
int N, M;
int R;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> S;

  for(int i = 1; i <= S.length(); i++) {
    for(int j = 0; j <= S.length() - i; j++) {
      tmp = S.substr(j, i);
      m.insert({tmp, 1});
    }
  }

  cout << m.size();

  return 0;
}