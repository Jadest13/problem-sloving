#include <bits/stdc++.h>

#define MAX 50

using namespace std;

int r1, c1, r2, c2;
int matrix[MAX][MAX];
int M;
int numlen;

int F(int y, int x) {
	int a = max(abs(y), abs(x));
	if(abs(y) == a) {
		if(y >= 0) {
			return (2*a+1)*(2*a+1)-(a-x);
		} else {
			return (2*a+1)*(2*a+1)-(a*4)-(a+x);
		}
	} else {
		if(x <= 0) {
			return (2*a+1)*(2*a+1)-(a*2)-(a-y);
		} else {
			return (2*a+1)*(2*a+1)-(a*6)-(a+y);
		}
	}
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> r1 >> c1 >> r2 >> c2;
  
  for(int i = r1; i <= r2; i++) {
  	for(int j = c1; j <= c2; j++) {
	  matrix[i-r1][j-c1] = F(i, j);
	  M = max(matrix[i-r1][j-c1], M);
  	}
  }
  
  while(M > 0) {
  	numlen++;
  	M /= 10;
  }
  
  for(int i = 0; i <= r2-r1; i++) {
  	for(int j = 0; j <= c2-c1; j++) {
  	  cout.width(numlen);
  	  cout << std::right << matrix[i][j] << " ";
	}
	cout << "\n";
  }

  return 0;
}
