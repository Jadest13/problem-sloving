#include <iostream>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;
using LL = long long;

int N;
int P, L;
int M;
string str;
int A, B;
map<int, vector<int>> DF;
map<int, int> NO;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> P >> L;
    DF[L].push_back(P);
    NO[P] = L;
  }
  cin >> M;
  for(int i = 1; i <= M; i++) {
    cin >> str;
    if(str == "add") {
      cin >> A >> B;
      DF[B].push_back(A);
      NO[A] = B;
    } else if(str == "recommend") {
      cin >> A;
      if(A < 0) {
        auto a = DF.begin();
        sort(DF[B].begin(), DF[B].end());
        cout << a->second[0] << "\n";
      } else {
        auto a = DF.end();
        a--;
        sort(DF[B].rbegin(), DF[B].rend());
        cout << a->second[0] << "\n";
      }
    } else {
      cin >> A;
      DF[NO[A]].erase(lower_bound(DF[NO[A]].begin(), DF[NO[A]].end(), A));
      if(DF[NO[A]].empty()) {
        DF.erase(DF.find(NO[A]));
      }
      NO.erase(NO.find(A));
    }
  }

  return 0;
}