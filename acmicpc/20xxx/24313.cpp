#include <iostream>
#include <algorithm>

using namespace std;

int A1, A0;
int C;
int N0;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> A1 >> A0;
  cin >> C >> N0;
  if(A1*N0+A0 <= C*N0 && C >= A1) cout << 1;
  else cout << 0;
}