#include <iostream>
#include <algorithm>
#include <string>

#define MAX 11
#define INF 1e9

using namespace std;

int N;
char c;
int A[MAX];
string mn = "9999999999", mx = "0000000000";

void F(int n, int b, int bit, string s) {
  if(n == N+1) {
    mn = min(mn, s);
    mx = max(mx, s);
    return;
  }
  for(int i = 0; i <= 9; i++) {
    if(bit & (1<<i)) continue;
    if(n == 0 || (A[n] > 0 && b > i) || (A[n] < 0 && b < i)) {
      F(n+1, i, bit | (1<<i), s+(char)(i+'0'));
    }
  }
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> c;
    if(c == '>') A[i] = 1;
    if(c == '<') A[i] = -1;
  }

  F(0, -1, 0, "");
  cout << mx << "\n" << mn;

  return 0;
}