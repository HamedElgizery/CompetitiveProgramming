#include <bits/stdc++.h>

using namespace std;

const int mxN = 2e5 + 1, mxK = 20;
vector<int> adj[mxN];
int parent[mxN][mxK][2];
int N;

pair<int, int> dfsMxDepth(int node, int p, int depth = 0) {
  pair<int, int> ret = {depth, node};
  for (auto it : adj[node]) {
    if (it == p) continue;
    ret = max(ret, dfsMxDepth(it, node, depth + 1));
  }
  return ret;
}

void dfsAnc(int node, int p, int x) {
  parent[node][0][x] = p;
  for (auto it : adj[node]) {
    if (it == p) continue;
    dfsAnc(it, node, x);
  }
}

int query(int node, int k, int x) {
  for (int i = 0; i < mxK; ++i)
    if (k & (1 << i))
      node = parent[node][i][x];
  if (!node) return -1;
  return node;
}

int main() {
  cin.tie(0)->sync_with_stdio(false);

  cin >> N;
  for (int i = 1; i < N; ++i) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  pair<int, int> L = dfsMxDepth(1, -1);
  pair<int, int> R = dfsMxDepth(L.second, -1);
  //cerr << L.second << ' ' << R.second << endl;
  dfsAnc(L.second, 0, 0);
  dfsAnc(R.second, 0, 1);
  for (int i = 0; i < 2; ++i)
    for (int j = 1; j < mxK; ++j)
      for (int k = 1; k <= N; ++k)
        parent[k][j][i] = parent[parent[k][j-1][i]][j-1][i];
  //for (int i = 0; i < 2; ++i) {
  //  for (int j = 0; j < mxK; ++j) {
  //    for (int k = 1; k <= N; ++k) {
  //      cout << parent[k][j][i] << ' ';
  //    }
  //    cout << endl;
  //  }
  //  cout << endl;
  //}
  int Q; cin >> Q;
  while (Q--) {
    int u, k; cin >> u >> k;
    cout << max(query(u, k, 0), query(u, k, 1)) << endl;;
  }
  return 0;
}
