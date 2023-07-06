#include <iostream>
#include <algorithm>
#include <regex>

using namespace std;

int T;
string M, S;

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> T;
  while(T--) {
    cin >> M;
    cin >> S;

    string R = "";

    for(int i = 0; i < 26; i++) {
      char ch = 'A' + i;
      string tmp = M;
      tmp[tmp.find('_')] = ch;
      regex re(tmp);

      if(regex_match(S, re)) {
        R += ch;
      }
    }

    if(R.size() == 0) cout << "!";
    else if(R.size() == 1) cout << R[0];
    else cout << "_";
    cout << "\n";
  }

  return 0;
}