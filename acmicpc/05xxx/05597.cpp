#include <iostream>

using namespace std;

int A[31];
int a;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for(int i = 0; i < 28; i++) {
    cin >> a;
    A[a] = 1;
  }

  for(int i = 1; i <= 30; i++) {
    if(!A[i]) {
      cout << i << "\n";
    }
  }

}