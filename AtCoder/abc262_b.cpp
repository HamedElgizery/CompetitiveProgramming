#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T& b) {return a = max(a, b);}
template<typename T> T umin(T& a, T& b) {return a = min(a, b);}

const int mxN = 101;

bool adj[mxN][mxN];

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int N, M; cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    int u, v; cin >> u >> v;
    --u, --v;
    adj[u][v]=adj[v][u]=1;
  }
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      if (!adj[j][i]) continue;
      for (int k = j + 1; k < N; ++k) {
        if (!adj[k][j]||!adj[k][i]) continue;
        ans++;
      }
    }
  }
  cout << ans;
  return 0;
}
