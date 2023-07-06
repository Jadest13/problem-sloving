#include <iostream>
#include <set>

using namespace std;

int T;
int k;
char ch;
int n;
multiset<int> MS;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  while(T--) {
    cin >> k;
    for(int i = 0; i < k; i++) {
      cin >> ch >> n;
      if(ch == 'I') {
        MS.insert(n);
      } else if(!MS.empty()) {
        if(n > 0) {
          auto iter = MS.end();
          iter--;
          MS.erase(iter);
        } else {
          MS.erase(MS.begin());
        }
      }
    }

    if(MS.empty()) {
      cout << "EMPTY\n";
    } else {
      auto iter = MS.end();
      iter--;
      cout << *iter << " " << *MS.begin() << "\n";
    }
    MS.clear();
  }
}