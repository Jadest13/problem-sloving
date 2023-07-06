#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int N, K;
string A[11];
map<string, int> MP;

void F(int n, string s, int bit) {
  if(n == K) MP[s]++;
  for(int i = 0; i < N; i++) {
    if(bit & (1<<i)) continue;
    F(n+1, s+A[i], bit | (1<<i));
  }
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  F(0, "", 0);
  
  cout << MP.size();

  return 0;
}