#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string N;
int R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  sort(N.begin(), N.end(), greater<>());
  if(N[N.length()-1] != '0') {
    cout << -1;
  } else {
    for(auto a : N) {
      R += a-'0';
    }
    if(R % 3) {
      cout << -1;
    } else {
      cout << N;
    }
  }

  return 0;
}