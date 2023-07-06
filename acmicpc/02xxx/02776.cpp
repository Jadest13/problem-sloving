#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int T;
int N, M;
map<int, int> MP;
int A;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  while(T--) {
    MP.clear();
    cin >> N;
    for(int i = 1; i <= N; i++) {
      cin >> A;
      MP[A] = 1;
    }
    cin >> M;
    for(int i = 1; i <= M; i++) {
      cin >> A;
      cout << MP[A] << "\n";
    }
  }

  return 0;
}