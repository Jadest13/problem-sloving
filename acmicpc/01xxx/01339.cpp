#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
string S;
int ARR[26];
int R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> S;
    reverse(S.begin(), S.end());
    int ten = 1;
    for(auto a : S) {
      ARR[a-'A'] += ten;
      ten *= 10;
    }
  }
  sort(ARR, ARR+26, [](int a, int b) {
    return a > b;
  });
  
  for(int i = 0; i < 10; i++) {
    R += (9-i)*ARR[i];
  }

  cout << R;

  return 0;
}