#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}


int main() {
  cin.tie(0)->sync_with_stdio(false);
  int N, M, K; cin >> N >> M >> K;
  vector<array<int, 3>> edges(M);
  for (auto &it : edges) cin >> it[0] >> it[1] >> it[2];
  vector<long long> dp(N+1, 1e18);
  dp[1] = 0;
  for (int i = 0; i < K; ++i) {
    int e; cin >> e;
    auto [u, v, w] = edges[e-1];
    umin(dp[v], dp[u] + w);
  }
  if (dp.back() == 1e18) cout << -1;
  else cout << dp.back();
  return 0;
}
