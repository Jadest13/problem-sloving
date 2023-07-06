#include <iostream>
#include <vector>
#include <algorithm>

typedef long long LL;

using namespace std;

int N;
string S[16];
LL A[15], T[51];
LL DP[1<<16][101];
LL total;
int K;

LL GCD(LL a, LL b) {
  if(b == 0) return a;
  return GCD(b, a % b);
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> S[i];
  }
  cin >> K;

  
  for(int i = 0; i < N; i++) {
    int tmp = 0;
    for(int j = 0; j < S[i].length(); j++) {
      tmp *= 10;
      tmp += S[i][j]-'0';
      tmp %= K;
    }
    A[i] = tmp;
  }

  T[0] = 1 % K;
  for(int i = 1; i <= 50; i++) {
    T[i] = (T[i-1]*10)%K;
  }

  DP[0][0] = 1;
  for(int i = 0; i < (1 << N); i++) {
    for(int j = 0; j < N; j++) {
      if(i&(1<<j)) continue;

      for(int l = 0; l < K; l++) {
        DP[i|(1<<j)][((l*T[S[j].length()])%K + A[j]) % K] += DP[i][l];
      }
    }
  }
  
  total = 1;
  for(int i = 1; i <= N; i++) {
    total *= i;
  }

  LL g = GCD(total, DP[(1<<N)-1][0]);

  cout << DP[(1<<N)-1][0]/g << '/' << total/g;


  return 0;
}