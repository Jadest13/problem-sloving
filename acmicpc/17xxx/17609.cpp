#include <iostream>
#include <algorithm>

using namespace std;

int N;
string str;

int F(string str, int l, int r, int a) {
  if(a >= 2) return 2;
  while(l < r) {
    if(str[l] != str[r]) {
      a = min(F(str, l+1, r, a+1), F(str, l, r-1, a+1));
      break;
    }
    l++;
    r--;
  }
  return a;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 1; i<= N; i++) {
    cin >> str;
    int l = 0, r = str.length()-1;
    cout << F(str, l, r, 0) << "\n";
  }

  return 0;
}