#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
string S;
int A[51][51];
int x, y;

double F() {

}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    cin >> S;
    for(int j = 1; j <= M; j++) {
      if(S[j-1] == '.')
        A[j][i] = 0;
      else if(S[j-i] == '#')
        A[j][i] = -1;
      else {
        A[j][i] = 1;
        x = j;
        y = i;
      }
    }
  }

  cout << F();


  return 0;
}