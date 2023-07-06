#include <iostream>
#include <algorithm>

using namespace std;

string str;
int R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for(int i = 1; i <= 8; i++) {
    cin >> str;
    for(int j = 0; j < 8; j++) {
      if((i+j)%2 && str[j] == 'F') R++;
    }
  }

  cout << R;

  return 0;
}