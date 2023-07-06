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
    for(int j = 1; j <= i*2-1; j++) {
      if(j%2) cout << "*";
      else cout << " ";
    }
    cout << "\n";
  }

  return 0;
}