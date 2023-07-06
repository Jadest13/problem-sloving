#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> V;
int R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while(1) {
    V.clear();
    R = 0;
    cin >> N;
    if(N == -1) break;
    for(int i = 1; i < N; i++) {
      if(N%i == 0) {
        R += i;
        V.push_back(i);
      }
    }
    if(R == N) {
      cout << N << " = ";
      for(int i = 0; i < V.size(); i++) {
        cout << V[i] << " ";
        if(i+1 != V.size()) cout << "+ ";
      }
    } else {
      cout << N << " is NOT perfect.";
    }
    cout << "\n";
  }

}