#include <iostream>
#include <algorithm>

using namespace std;

int N;
string R;

void F(string S, int L) {
  if(!R.empty()) return;
  
  for(int i = 1; i <= L/2; i++) {
    if(S.substr(L-i, i) == S.substr(L-i*2, i)) {
      return;
    }
  }

  if(L > N) {
    return;
  } else if(L == N) {
    R = S;
    return;
  } else {
    F(S + "1", L + 1);
    F(S + "2", L + 1);
    F(S + "3", L + 1);
  }
}

int main(void) {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  F("", 0);

  cout << R;

  exit(0);
}