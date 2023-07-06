#include <iostream>
#include <algorithm>

using namespace std;

int A, B;

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  while(1) {
    cin >> A >> B;

    if(!A && !B) break;

    if(A > B) cout << "Yes\n";
    else cout << "No\n";
  }

  return 0;
}