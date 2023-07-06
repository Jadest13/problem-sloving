#include <iostream>
#include <algorithm>

using namespace std;

string N;
int R;

int main(void) {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  while(1) {
    cin >> N;
    if(!N.compare("0")) {
      break;
    }

    R = 1;

    for(int i = 0; i < N.size()/2; i++) {
      if(N[i]!=N[N.size()-i-1]) {
        R = 0;
        break;
      }
    }

    if(R) {
      cout << "yes\n";
    } else {
      cout << "no\n";
    }
  }

  exit(0);
}