#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<string> fibo;

string BI_add(string a, string b) {
  int tmp = 0;
  string S = "";

  while (!a.empty() || !b.empty() || tmp) {
    if (!a.empty()) {
      tmp += a.back() - '0';
      a.pop_back();
    }

    if (!b.empty()) {
      tmp += b.back() - '0';
      b.pop_back();
    }

    S += ((tmp % 10) + '0');
    tmp /= 10;
  }

  reverse(S.begin(), S.end());
  return S;
}

string F(int a) {
  
  fibo.push_back("0");
  fibo.push_back("1");

  for(int i = 2; i <= a; i++) {
    fibo.push_back(BI_add(fibo[i-1], fibo[i-2]));
  }

  return fibo[a];
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  cout << F(n);

  return 0;
}