#include <iostream>
#include <algorithm>

using namespace std;

string S;
int ARR[26];
string R;
char c;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> S;
  for(auto a : S) {
    ARR[a-'A']++;
  }
  for(int i = 0; i < 26; i++) {
    while(ARR[i] >= 2) {
      ARR[i] -= 2;
      R.push_back(i+'A');
    }
  }
  for(int i = 0; i < 26; i++) {
    if(!ARR[i]) continue;
    if(c) {
      c = -1;
      break;
    }
    c = i+'A';
    R.push_back(c);
  }

  if(c == -1) R = "I'm Sorry Hansoo";
  else {
    for(int i = R.size()-1+(c?-1:0); i >= 0; i--) {
      R.push_back(R[i]);
    }
  }

  cout << R;

  return 0;
}