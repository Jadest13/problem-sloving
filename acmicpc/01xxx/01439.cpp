#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string S;
int A, B;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> S;
  if(S[0] == '1') {
    A++;
  } else {
    B++;
  }

  for(int i = 1; i < S.length(); i++) {
    if(S[i] != S[i-1]) {
      if(S[i] == '1') {
        A++;
      } else {
        B++;
      }
    }
  }

  cout << min(A, B);

  return 0;
}