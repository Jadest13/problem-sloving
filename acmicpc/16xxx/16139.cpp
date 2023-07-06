#include <iostream>
#include <algorithm>

using namespace std;

string S;
int P[26][200001];
int q;
char a;
int l, r;

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> S;
  for(int i = 1; i <= S.length(); i++) {
    for(int j = 0; j < 26; j++) {
      if(S[i-1]-'a' == j) {
        P[j][i] = P[j][i-1]+1;
      } else {
        P[j][i] = P[j][i-1];
      }
    }
  }
  cin >> q;
  for(int i = 0; i < q; i++) {
    cin >> a >> l >> r;
    cout << P[a-'a'][r+1] - P[a-'a'][l] << "\n";
  }

  return 0;
}