#include <iostream>

using namespace std;

int A[101][101];
int N;
int x, y;
int R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> x >> y;
    for(int j = y; j < y + 10; j++) {
      for(int k = x; k < x + 10; k++) {
        if(!A[j][k]) {
          A[j][k] = 1;
          R++;
        }
      }
    }
  }

  cout << R;
}