#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int a;
vector<int> V;
int R = 1;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> a;
    V.push_back(a);
  }
  sort(V.begin(), V.end());

  for(int i = 0; i < N; i++) {
    if(V[i] > R) break;
    R += V[i];
  }
  
  cout << R;

  return 0;
}