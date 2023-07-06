#include <iostream>
#include <algorithm>

using namespace std;

long long S;

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> S;

  for(long long i = 1; ; i++) {
    if(S < i*(i+1)/2) {
      cout << i-1;
      break;
    }
  }
  
  return 0;
}