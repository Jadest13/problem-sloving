#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int S, a;
vector<int> V;
int sum, R = 100001;
int l, r;

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> S;
  for(int i = 0; i < N; i++) {
    cin >> a;
    V.push_back(a);
  }

  l = 0, r = 0;
  sum = V[0];
  while(l <= r && r < N) {
    if(sum < S) sum += V[++r];
    else {
      R = min(R, r-l+1);
      sum -= V[l++];
    }
  }

  cout << ((R==100001)?0:R);

  return 0;
}