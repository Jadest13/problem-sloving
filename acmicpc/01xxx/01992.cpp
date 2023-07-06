#include <iostream>
#include <algorithm>

#define MAX 65

using namespace std;

int N;
int A[MAX][MAX];
string str;

void F(int x, int y, int w, int h) {
  int tmp = 0;
  for(int i = y; i < y+h; i++) {
    for(int j = x; j < x+w; j++) {
      if(A[i][j]) tmp++;
    }
  }
  if(tmp == 0) cout << 0;
  else if(tmp == w*h) cout << 1;
  else {
    cout << "(";
    F(x, y, w/2, h/2);
    F(x+w/2, y, w/2, h/2);
    F(x, y+h/2, w/2, h/2);
    F(x+w/2, y+h/2, w/2, h/2);
    cout << ")";
  }
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> str;
    for(int j = 0; j < N; j++) {
      A[i][j] = str[j] - '0';
    }
  }

  F(0, 0, N, N);

  return 0;
}