#include <iostream>
#include <algorithm>

using namespace std;

string A[6];
int len;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for(int i = 1; i <= 5; i++) {
    cin >> A[i];
    len = max(len, (int)A[i].length());
  }

  for(int i = 0; i < len; i++) {
    for(int j = 1; j <= 5; j++) {
      if(i >= A[j].length()) continue;
      cout << A[j][i];
    }
  }

  return 0;
}