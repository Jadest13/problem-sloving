#include <iostream>
#include <algorithm>

using namespace std;
using LL = long long;

LL N;
LL R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 1; i < N; i++) {
    for(int j = i+1; j <= N; j++) {
      R++;
    }
  }
  cout << R << "\n" << 2;
}