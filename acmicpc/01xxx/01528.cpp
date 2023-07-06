#include <iostream>
#include <queue>
#include <algorithm>

#define INF 1e9
#define FINF 444444
#define SINF 777777

using namespace std;

typedef struct {
  int a;
  int n;
  vector<int> V;
} kms;

struct cmp {
  bool operator()(kms a, kms b) {
    if(a.n == b.n) {
      // for(int i = 0; i < a.n; i++) {
      //   if(a.V[i] == b.V[i]) continue;
      //   else return a.V[i] > b.V[i];
      // }
      return a.a < b.a;
      // if(a.a == b.a) {
      // } else return a.a > b.a;
    } else return a.n < b.n;
  }
};

int N;
priority_queue<kms, vector<kms>, cmp> PQ;
int KMS[1<<8];
int visit[1000001];
int mn = INF;
vector<int> R;

void init(int n, int a) {
  if(a > 1000000) return;
  KMS[n] = a*10+4;
  KMS[n+1] = a*10+7;
  init(n*2, KMS[n]);
  init((n+1)*2, KMS[n+1]);
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  init(2, 0);

  PQ.push({0});
  visit[0] = 1;
  
  while(!PQ.empty()) {
    cout << PQ.top().a << " : ";
    for(auto a : PQ.top().V) {
      cout << a << " ";
    }
    cout << ": ";
    int pa = PQ.top().a;
    int pn = PQ.top().n;
    vector<int> pv = PQ.top().V;
    PQ.pop();
    if(pa == N) {
      if(pn < mn) {
        R = pv;
        mn = pn;
        continue;
      }
    }
    if(pn >= mn) continue;

    for(int i = 1<<7 - 2; i >= 2; i--) {
      if(pa+KMS[i] > N) continue;
      cout << KMS[i] << " ";

      vector<int> nv = pv;
      nv.push_back(KMS[i]);
      
      PQ.push({pa+KMS[i], pn+1, nv});
      visit[pa+KMS[i]] = 1;
    }
    cout << "\n";
  }

  if(mn == INF) {
    cout << -1;
  } else {
    for(auto a : R) {
      cout << a << " ";
    }
  }

  return 0;
}