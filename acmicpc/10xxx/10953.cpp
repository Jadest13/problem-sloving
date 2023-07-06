#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int T;
string S;
int ret;

void F() {
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> T;
  while(T--) {
    cin >> S;
    ret = (S[0]-'0')+(S[2]-'0');
    cout << ret << "\n";
  }
  

  return 0;
}