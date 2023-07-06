#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int M, N;
char str[20];

int F(char tmp[], int count) {
  for(int i = 1; i <= N; i++) {
    if(strchr(tmp, i+'0') == NULL && count==0 || (count > 0 && i > tmp[(count-1)*2] - '0')) {

      tmp[count*2] = i + '0';
      if(count == M-1) {
        tmp[count*2+1] = '\0';
        printf("%s\n", tmp);
      } else {
        tmp[count*2+1] = ' ';
        F(tmp, count+1);
      }
    }
  }
}

int main(void) {
  cin >> N >> M;

  F(str, 0);


  exit(0);
}