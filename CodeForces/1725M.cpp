#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

const int mxN = 1e5;
vector<pair<int, long long>> adj[2][mxN];
int N, M;

void dijkstra() {
  priority_queue<array<long long, 3>, vector<array<long long, 3>>, greater<array<long long, 3>>> pq;
  pq.push({0, 0, 0});
  vector<vector<long long>> dist(2, vector<long long>(N, LLONG_MAX));
  while (!pq.empty()) {
    auto curr = pq.top();
    pq.pop();
    if (dist[curr[2]][curr[1]] < curr[0]) continue;
    for (int i = curr[2]; i < 2; ++i) {
      for (auto it : adj[i][curr[1]]) {
        long long cost = curr[0] + it.second;
        if (cost < dist[i][it.first]) {
          umin(dist[i][it.first], cost);
          pq.push({cost, it.first, i});
        }
      }
    }
  }
  for (int i = 1; i < N; ++i) {
    long long ans = min(dist[0][i], dist[1][i]);
    if (ans == LLONG_MAX) {
      cout << -1 << ' ';
    }
    else cout << ans << ' ';
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    int u, v, w; cin >> u >> v >> w;
    adj[0][--u].push_back({--v, w});
    adj[1][v].push_back({u, w});
  }
  dijkstra();
  return 0;
}
