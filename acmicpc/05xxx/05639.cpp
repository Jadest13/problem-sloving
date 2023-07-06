#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int A;
vector<int> V;

void F(int s, int e) {

  if(s >= e) return;

  int a = V[s];
  int b = e;

  for(int i = s+1; i < e; i++) {
    if(V[i] > a) {
      b = i;
      break;
    }
  }
  F(s+1, b);
  F(b, e);

  cout << a << "\n";
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  while(1) {
    cin >> A;
    if(cin.eof()) break;
    else V.push_back(A);
  }

  F(0, V.size());

  return 0;
}