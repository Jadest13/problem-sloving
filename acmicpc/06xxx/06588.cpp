#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int P[1000001];
vector<int> VP;
int check;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  P[1] = -1;
  for(int i = 1; i <= 1000000; i++) {
    if(!P[i]) {
      P[i] = 1;
      for(int j = i*2; j <= 1000000; j += i) {
        P[j] = -1;
      }
    }
  }
  for(int i = 1; i <= 1000000; i++) {
    if(P[i] == 1) {
      VP.push_back(i);
    }
  }
a
  while(1) {
    check = 0;
    cin >> N;
    if(N == 0) break;

    for(int i = 0; i < VP.size() && !check; i++) {
      for(int j = i+1; j < VP.size() && !check; j++) {
        if(VP[i] + VP[j] == N) {
          cout << N << " = " << VP[i] << " + " << VP[j] << "\n";
          check = 1;
        }
      }
    }

    if(!check) cout << "Goldbach's conjecture is wrong.\n";
  }

  return 0;
}