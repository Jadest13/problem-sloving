#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, L;
int a;
vector<int> V;
int P;
int R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> L;
  for(int i = 0; i < N; i++) {
    cin >> a;
    V.push_back(a);
  }
  sort(V.begin(), V.end());

  P = V[0];
  R = 1;
  for(int i = 1; i < V.size(); i++) {
    if(V[i] - P < L) continue;
    P = V[i];
    R++;
  }

  cout << R;
  
  return 0;
}