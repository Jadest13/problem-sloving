#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
string S;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;
  cin >> S;
  S.push_back('E');

  int i = 0;
  int len = S.length()-1;
  while(K) {
    int t = i;
    while(S[t+1] == 'X') t++;
    if(S[i] < S[t+1]) {
      S[i] = 'X';
      K--;
      while(i > 0 && S[i] == 'X') i--;
    } else {
      i = ++i%len;
    }
  }

  for(auto a : S) {
    if(a == 'X' || a == 'E') continue;
    cout << a;
  }

  return 0;
}