#include <iostream>
#include <algorithm>

using namespace std;

int N;
string S[1001];
int a;
int mx;
string R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> S[i];
  }
  sort(S, S+N);

  for(int i = 0; i < N; i++) {
    a++;
    if(S[i] != S[i+1]) {
      if(a > mx) {
        mx = a;
        R = S[i];
      }
      a = 0;
    }
  }

  cout << R;

  return 0;
}