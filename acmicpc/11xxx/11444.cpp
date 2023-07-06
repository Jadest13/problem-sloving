#include<iostream>
#include<vector>

using namespace std;

typedef vector<vector<long long>> matrix;
matrix operator*(matrix &a, matrix &b) {
  matrix c(2, vector<long long>(2));

  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 2; j++) {
      for(int k = 0; k < 2; k++) {
        c[i][j] += a[i][k]*b[k][j];
      }
      c[i][j] %= 1000000007;
    }
  }
  
  return c;
}

long long n;
matrix fibo = {{1,1}, {1,0}};
matrix R = {{1,0}, {0,1}};

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  while(n > 0) {
    
    if(n % 2 == 1) {
      R = R*fibo;
    }
    fibo = fibo*fibo;

    n/=2;
  }

  cout << R[0][1];
}