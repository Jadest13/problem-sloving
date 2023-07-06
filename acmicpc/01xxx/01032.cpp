#include <iostream>
#include <algorithm>

using namespace std;

int N;
string S, str;

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  cin >> S;
  for(int i = 1; i < N; i++) {
    cin >> str;
    for(int j = 0; j < S.size(); j++) {
      if(S[j] != str[j]) {
        S[j] = '?';
      }
    }
  }

  cout << S;


  return 0;
}