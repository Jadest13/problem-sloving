#include <iostream>
#include <algorithm>

using namespace std;

string S;
int A[26];

int main(void) {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> S;

  for(int i = 0; i < S.size(); i++) {
    A[S[i]-'a']++;
  }

  for(int i = 0; i < 26; i++) {
    cout << A[i] << " ";
  }

  exit(0);
}