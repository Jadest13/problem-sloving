#include <iostream>
#include <algorithm>

using namespace std;

long long N;

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  if(N%5 == 2 || N%5 == 0) {
    cout << "CY";
  } else {
    cout << "SK";
  }

  return 0;
}