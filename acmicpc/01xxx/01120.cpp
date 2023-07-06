#include <iostream>
#include <algorithm>

using namespace std;

string S1, S2;
int R = 51;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> S1 >> S2;
  for(int i = 0; i <= S2.length() - S1.length(); i++) {
    int tmp = 0;
    for(int j = 0; j < S1.length(); j++) {
      if(S1[j] != S2[i+j]) tmp++;
    }
    R = min(R, tmp);
  }

  cout << R;

  return 0;
}