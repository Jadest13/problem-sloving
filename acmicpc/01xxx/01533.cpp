#include <iostream>

#define LL long long
#define MOD 1000003

using namespace std;

int N, S, E;
string str;
LL T;
LL M[50][50], R[50][50];

void mmul(LL l[50][50], LL r[50][50]) {
  LL ret[50][50] = {0};
  for(int i = 0; i < N*5; i++) {
    for(int j = 0; j < N*5; j++) {
      for(int k = 0; k < N*5; k++) {
        ret[i][j] += l[i][k]*r[k][j];
        ret[i][j] %= MOD;
      }
    }
  }
  for(int i = 0; i < N*5; i++) {
    for(int j = 0; j < N*5; j++) {
      l[i][j] = ret[i][j];
    }
  }
}

void mpow(LL m[50][50], int t) {
  if(t == 1) {
    for(int i = 0; i < N*5; i++) {
      for(int j = 0; j < N*5; j++) {
        m[i][j] = M[i][j];
      }
    }
  } else {
    if(t%2) {
      mpow(m, t-1);
      mmul(m, M);
    } else {
      mpow(m, t/2);
      mmul(m, m);
    }
  }
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> S >> E >> T;

  for(int i = 0; i < N; i++) {
    for(int j = 1; j < 5; j++) {
      M[i*5+j][i*5+j-1] = 1;
    }
  }

  for(int i = 0; i < N; i++) {
    cin >> str;
    for(int j = 0; j < N; j++) {
      if(str[j]-'0' != 0) {
        M[i*5][j*5+str[j]-'0'-1] = 1;
      }
    }
  }

  mpow(R, T);
  cout << R[5*(S-1)][5*(E-1)];
}