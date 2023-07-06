#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int D[21][21][21];
int a, b, c;

int F(int a, int b, int c) {
  if(a <= 0 || b <= 0 || c <= 0) {
    return 1;
  }

  if(a > 20 || b > 20 || c > 20) {
    return F(20, 20, 20);
  }

  if(D[a][b][c]) {
    return D[a][b][c];
  }

  if(a < b && b < c) {
    D[a][b][c] = F(a, b, c-1) + F(a, b-1, c-1) - F(a, b-1, c);
    return D[a][b][c];
  }

  D[a][b][c] = F(a-1, b, c) + F(a-1, b-1, c) + F(a-1, b, c-1) - F(a-1, b-1, c-1);
  return D[a][b][c];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  while(1) {
    cin >> a >> b >> c;

    if(a == -1 && b == -1 && c == -1) {
      break;
    }

    printf("w(%d, %d, %d) = %d\n", a, b, c, F(a,b,c));
  }

  return 0;
}