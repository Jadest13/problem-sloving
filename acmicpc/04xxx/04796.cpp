#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int i;
int L, P, V;
int R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while(++i) {
    cin >> L >> P >> V;
    if(!L && !P && !V) break;
    R = (V/P)*L + (((V%P)>L)?L:(V%P));
    cout << "Case " << i << ": " << R << "\n"; 
  }

  return 0;
}