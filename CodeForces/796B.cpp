#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int x = 1;
  int N, M, K; cin >> N >> M >> K;
  map<int, bool> hasHole;
  for (int i = 0; i < M; ++i) {
    int h; cin >> h;
    hasHole[h] = 1;
  }
  bool fell = hasHole[x];
  while (K-- && !fell) {
    int u, v; cin >> u >> v;
    if (x == u) {
      x = v;
      if (hasHole[v]) fell = 1;
    }
    else if (x == v) {
      x = u;
      if (hasHole[u]) fell = 1;
    }
  }
  cout << x;
  return 0;
}
