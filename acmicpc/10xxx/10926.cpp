#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char buf[100];

int main(void) {
  cin >> buf;
  strcat(buf, "??!");
  printf("%s", buf);

  exit(0);
}