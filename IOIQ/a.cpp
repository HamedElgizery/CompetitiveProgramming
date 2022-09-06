#include <bits/stdc++.h>

using namespace std;

const int mxN = 2e5 + 10;
int timer, in[mxN], out[mxN];
int childs[mxN];
bool vis[mxN];
vector<int> adj[mxN];

void dfs(int node) {
  vis[node] = 1;
  childs[node] = 1;
  in[node] = ++timer;
  for (auto it : adj[node]) {
    dfs(it);
    childs[node] += childs[it];
  }
  out[node] = ++timer;
}

int main() {
  int N; cin >> N;
  for (int i = 0; i < N; ++i) {
    int p; cin >> p;
    adj[p].push_back(i + 1);
  }
  dfs(0);
  int Q; cin >> Q;
  while (Q--) {
    int k; cin >> k;
    set<pair<pair<int, int>, int>> ranges;
    for (int i = 0; i < k; ++i) {
      int p; cin >> p;
      ranges.insert({{in[p], out[p]}, p});
    }
    int last = 0;
    int ans = 0;
    for (auto it : ranges) {
      if (it.first.second < last) continue;
      else {
        last = it.first.second;
        ans += childs[it.second];
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
