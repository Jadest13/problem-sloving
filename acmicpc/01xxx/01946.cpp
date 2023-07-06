#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using PII = pair<int, int>;

int T;
int N;
int a, b;
vector<PII> V;
int tmp;
int R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  while(T--) {
    V.clear();
    R = 1;
    tmp = 0;

    cin >> N;

    for(int i = 1; i <= N; i++) {
      cin >> a >> b;
      V.push_back({a, b});
    }
    sort(V.begin(), V.end());
    for(int i = 1; i < N; i++) {
      if(V[tmp].second > V[i].second) {
        tmp = i;
        R++;
      }
    }
    cout << R << "\n";
  }

  return 0;
}