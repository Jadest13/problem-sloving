#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int i;

int main(void) {

  while(++i) {
    cin >> n;
    if(!n) break;

    cout << i << ". ";
    cout << ((n%2)?"odd ":"even ");
    cout << (3*(((3*n)+1)/2))/9 << "\n";
  }

  return 0;
}