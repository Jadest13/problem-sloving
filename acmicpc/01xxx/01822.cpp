#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int A, B;
int a;
set<int> MP;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> A >> B;
  for(int i = 0; i < A; i++) {
    cin >> a;
    MP.insert(a);
  }
  for(int j = 0; j < B; j++) {
    cin >> a;
    if(MP.find(a) != MP.end()) {
      MP.erase(a);
    }
  }
  cout << MP.size() << "\n";
  for(auto a : MP) {
    cout << a << " ";
  }

  return 0;
}