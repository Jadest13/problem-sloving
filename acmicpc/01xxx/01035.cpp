#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
  int x, y;
} Point;

int str;
int A[6][6];
vector<Point> V;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for(int i = 1; i <= 5; i++) {
    cin >> str;
    for(int j = 1; j <= 5; j++) {
      if(str[j-1] == '*') {
        A[i][j] = 1;
        V.push_back({j, i});
      }
    }
  }

  return 0;
}