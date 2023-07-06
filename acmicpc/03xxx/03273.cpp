#include <iostream>
#include <algorithm>
#include <vector>

#define INF INT32_MAX

using namespace std;

int n, a, x;
vector<int> V;
int R;
int l, r;

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a;
    V.push_back(a);
  }
  cin >> x;

  sort(V.begin(), V.end());
  l = 0, r = n-1;

  while(l < r) {
    if(V[l]+V[r] == x) {
      R++;
      l++;
      r--;
    } else if(V[l]+V[r] < x) {
      l++;
    } else {
      r--;
    }
  }

  cout << R;

  return 0;
}