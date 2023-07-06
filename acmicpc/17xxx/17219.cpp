#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int N, M;
map<string, string> MP;
string A, B;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    cin >> A >> B;
    MP[A] = B;
  }
  for(int i = 1; i <= M; i++) {
    cin >> A;
    cout << MP[A] << "\n";
  }

  return 0;
}