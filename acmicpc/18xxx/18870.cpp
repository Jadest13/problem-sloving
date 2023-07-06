#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, a;
vector<int> X, V;

int main() {
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> a;
    X.push_back(a);
    V.push_back(a);
  }

  sort(V.begin(), V.end());
  V.erase(unique(V.begin(), V.end()), V.end());

  for(int i = 0; i < N; i++) {
    cout << lower_bound(V.begin(), V.end(), X[i]) - V.begin() << " ";
  }
}