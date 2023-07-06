#include <iostream>
#include <algorithm>

using namespace std;

int N;

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  for(int i = 1; i <= N; i++) {
    for(int j = 0; j < N-i; j++) {
      cout << " ";
    }
    for(int j = 0; j < i; j++) {
      cout << "*";
    }
    cout << "\n";
  }
  for(int i = N-1; i > 0; i--) {
    for(int j = 0; j < N-i; j++) {
      cout << " ";
    }
    for(int j = 0; j < i; j++) {
      cout << "*";
    }
    cout << "\n";
  }

  return 0;
}