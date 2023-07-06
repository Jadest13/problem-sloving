#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
using LL = long long;

int N, K;
int a;
int SUM[200001];
map<LL, int> MP;
LL R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;
  for(int i = 1; i <= N; i++) {
    cin >> a;
    SUM[i] = SUM[i-1] + a;
  }
  for(int i = 1; i <= N; i++) {
    if(SUM[i] == K) R++;
    R += MP[SUM[i] - K];
    MP[SUM[i]]++;
  }
  cout << R;

  return 0;
}