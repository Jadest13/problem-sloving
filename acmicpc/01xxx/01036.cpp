#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define MAX 55

using namespace std;

typedef struct {
  int i;
  int a[MAX];
} c36;

int N, K;
char str[MAX][MAX];
c36 cnt[36];
int res[MAX];
int flag;

int cvt36toi(char c) {
  if(c < 'A') return c-'0';
  else return c-'A' + 10;
}

char cvt36toc(int i) {
  if(i < 10) return i+'0';
  else return i-10+'A';
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for(int i = 0; i < 36; i++) {
    cnt[i].i = i;
  }

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> str[i];
    for(int j = strlen(str[i])-1; j >= 0; j--) {
      int a = cvt36toi(str[i][j]);
      int idx = MAX-(strlen(str[i])-j);

      cnt[a].a[idx]+= 36-a-1;
      while(cnt[a].a[idx] >= 36) {
        cnt[a].a[idx] -= 36;
        idx--;
        cnt[a].a[idx]++;
      }
    }
  }
  cin >> K;

  sort(cnt, cnt+36, [](c36 a, c36 b) {
    for(int i = 0; i < MAX; i++) {
      if(a.a[i] > b.a[i]) return true;
      if(a.a[i] < b.a[i]) return false;
    }
    return false;
  });

  for(int i = 1; i <= N; i++) {
    for(int j = 0; j < strlen(str[i]); j++) {
      for(int k = 0; k < K; k++) {
        if(str[i][j] == cvt36toc(cnt[k].i)) {
          str[i][j] = 'Z';
        }
      }
    }
  }

  for(int i = 1; i <= N; i++) {
    for(int j = strlen(str[i])-1; j >= 0; j--) {
      int a = cvt36toi(str[i][j]);
      int idx = strlen(str[i])-j-1;
      res[idx] += a;
    }
  }

  for(int i = 0; i < MAX; i++) {
    if(res[i] >= 36) {
      res[i+1] += res[i]/36;
      res[i] %= 36;
    }
  }

  for(int i = MAX-1; i >= 0; i--) {
    if(!flag && res[i] == 0) {
      continue;
    }
    flag = 1;
    cout << cvt36toc(res[i]);
  }
  if(!flag) cout << "0";

  return 0;
}