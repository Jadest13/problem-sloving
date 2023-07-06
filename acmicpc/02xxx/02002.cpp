#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int N;
string str;
map<string, int> MP;
string A[1001];
int R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> str;
    MP[str] = i;
  }
  for(int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  for(int i = N; i > 0; i--) {
    for(int j = N; j > i; j--) {
      if(MP[A[i]] > MP[A[j]]) {
        R++;
        break;
      }
    }
  }
  cout << R;

  return 0;
}