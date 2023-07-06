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
    if(i==N) {
      for(int j = 0; j < i*2-1; j++) {
        cout << "*";
      }
    } else {
      for(int j = 0; j < N-i; j++) {
        cout << " ";
      }
      cout << "*";
      if(i > 1) {
        for(int j = 0; j < i*2-3; j++) {
          cout << " ";
        }
        cout << "*";
      }
    }
    cout << "\n";
  }

  return 0;
}