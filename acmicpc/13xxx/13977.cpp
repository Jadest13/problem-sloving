#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

typedef long long LL;

int M;
LL N, K;
LL fact[4000001];

LL dcpow(LL a, LL b) {
  if(b == 1) return a % MOD;
  if(b & 1) return (dcpow(a, b-1) * a) % MOD;
  return dcpow((a * a) % MOD, b/2);
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  fact[0] = fact[1] = 1;
  for(int i = 2; i <= 4000000; i++) {
    fact[i] = (fact[i-1] * i) % MOD;
  }

  cin >> M;
  while(M--) {
    cin >> N >> K;
    cout << (fact[N] * dcpow((fact[N-K] * fact[K]) % MOD, MOD-2)) % MOD << "\n";
  }
}