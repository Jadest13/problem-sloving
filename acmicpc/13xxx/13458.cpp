#include <iostream>
#include <algorithm>

using namespace std;

int N, A[1000001];
int B, C;
long res;

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  cin >> B >> C;
  for(int i = 1 ; i <= N; i++) {
    A[i] -= B;
    res += 1;
    if(A[i] > 0) {
      res += A[i]/C + ((A[i]%C)?1:0);
    }
  }

  cout << res;

  return 0;
}