#include <iostream>
#include <algorithm>
#include <cstring>

#define MAX 51

using namespace std;
using LL = long long;

char str[MAX], form[MAX];
int N, S, E;

LL F(int n, int s, int l, int r) {
  LL pos = s;
  if(n == N) {
    if(pos + strlen(str) < l) return pos + strlen(str);

    for(int i = 0; i < strlen(str); i++) {
      if(l <= pos+i && pos+i <= r) {
        cout << str[i];
      }
    }
    return pos + strlen(str);
  }
  for(int i = 0; i < strlen(form); i++) {
    if(form[i] == '$') {
      pos = F(n+1, pos, l, r);
    } else {
      cout << form[i];
      pos++;
    }
    if(pos > r) break;
  }
  .
  return pos;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> str;
  cin >> form;
  cin >> N;
  cin >> S >> E;

  int pos = F(0, 1, S, E);
  for(int i = pos; i <= E; i++) {
    cout << "-";
  }

  return 0;
}