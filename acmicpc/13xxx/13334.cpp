#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N;
long long h, o;
long long d;
vector<pair<int, int>> V;
priority_queue<int, vector<int>, greater<int>> PQ;
int R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> h >> o;
    if(h < o) V.push_back({o, h});
    else V.push_back({h, o});
  }
  cin >> d;

  sort(V.begin(), V.end());

  for(auto a : V) {
    int e = a.first;
    int s = a.second;

    if(e-s <= d) {
      PQ.push(s);
      
      while(!PQ.empty()) {
        if(PQ.top() < e-d) PQ.pop();
        else {
          R = max(R, (int)PQ.size());
          break;
        }
      }
    }
  }

  cout << R;
}