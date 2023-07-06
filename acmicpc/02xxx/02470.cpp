#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
long long a;
vector<long long> V;
long long R;
int l, r;
long long diff;
long long R1, R2;

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> a;
    V.push_back(a);
  }

  sort(V.begin(), V.end());
  l = 0, r = N-1;

  diff = 2000000000;
  R1 = V[l];
  R2 = V[r];
  while(l < r) {
    long long sum = V[l]+V[r];

    if(abs(sum) < diff) {
      diff = abs(sum);
      R1 = V[l];
      R2 = V[r];
    }

    if(sum > 0) {
      r--;
    } else if(sum < 0) {
      l++;
    } else {
      R1 = V[l];
      R2 = V[r];
      break;
    }
  }

  cout << R1 << " " << R2;

  return 0;
}