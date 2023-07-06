#include <iostream>
#include <algorithm>

using namespace std;

int T;
int V, E;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  while(T--) {
    cin >> V >> E;
    cout << 2-V+E << "\n";
  }

  return 0;
}