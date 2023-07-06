#include <iostream>
#include <algorithm>

#define MAX 101

using namespace std;

int N, K;
int a;
int R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;
  for(int i = 1; i <= N; i++) {
    if(N%i == 0) a++;
    if(a==K) {
      R = i;
      break;
    }
  }
  cout << R;

  return 0;
}