#include <iostream>
#include <algorithm>

#define MAX 1001

using namespace std;

int N;
int A[MAX];
int DP[MAX];

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  while(N > 0) {
    N -= 4;
    cout << "long ";
  }
  cout << "int";

  return 0;
}