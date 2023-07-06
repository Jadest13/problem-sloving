#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 51

using namespace std;

int N, M;
string S;
int PRO1[MAX][MAX], PRO2[MAX][MAX];
int check;
int R;

void F(int y, int x) {
  for(int i = y; i <= y+2; i++) {
    for(int j = x; j <= x+2; j++) {
      PRO1[i][j] = !PRO1[i][j];
    }
  }
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    cin >> S;
    for(int j = 1; j <= M; j++) {
      PRO1[i][j] = S[j-1]-'0';
    }
  }
  for(int i = 1; i <= N; i++) {
    cin >> S;
    for(int j = 1; j <= M; j++) {
      PRO2[i][j] = S[j-1]-'0';
    }
  }

  for(int i = 1; i <= N-2; i++) {
    for(int j = 1; j <= M-2; j++) {
      if(PRO1[i][j] != PRO2[i][j]) {
        F(i, j);
        R++;
      }
    }
  }
  
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      if(PRO1[i][j] != PRO2[i][j]) {
        check = -1;
        break;
      }
    }
    if(check) break;
  }
  
  cout << (check?check:R);

  return 0;
}