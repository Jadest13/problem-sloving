#include <iostream>
#include <string>

using namespace std;

string S;
int A[26], M, k;
char R = '?';

int main() {

  getline(cin, S);

  for(int i = 0; i < S.length(); i++) {
    k = (S[i]-'A') % ('a'-'A');
    A[k]++;

    if(A[k] == M) {
      R = '?';
    } else if(A[k] > M) {
      M = A[k];
      R = S[i];
    }
  }

  if(R >= 'a') R -= 'a'-'A';

  cout << R;

  return 0;
}