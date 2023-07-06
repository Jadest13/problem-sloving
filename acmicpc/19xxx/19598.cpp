#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using PII = pair<int, int>;

int N;
int S, E;
vector<PII> V;
int cnt;
int R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> S >> E;
    V.push_back({S, 1});
    V.push_back({E, -1});
  }
  sort(V.begin(), V.end());

  for(auto a : V) {
    cnt += a.second;
    R = max(R, cnt);
  }

  cout << R;

  return 0;
}