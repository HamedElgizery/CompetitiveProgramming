#include <bits/stdc++.h>

using namespace std;

const int mxN = 2e5 + 10;
int head[mxN], heavy[mxN], pos[mxN], depth[mxN], parent[mxN], currPos, values[mxN];
vector<int> adj[mxN];
vector<tuple<int, int, long long>> edges;
int N;

struct SegmentTree {
  int N;
  vector<long long> seg;
  SegmentTree(int N) : N(N) {
    seg.assign(N * 2, 0);
  }
 
  void update(int node, int l, int r, int idx, long long val) {
    if (l == r && l == idx) return void(seg[node] = val);
    if (idx < l || r < idx) return;
    int mid = (l + r) >> 1;
    update(node + 1, l, mid, idx, val);
    update(node + ((mid - l + 1) << 1), mid + 1, r, idx, val);
    seg[node] = max(seg[node + 1], seg[node + ((mid - l + 1) << 1)]);
  }
 
  long long query(int node, int l, int r, int lt, int rt) {
    if (lt <= l && r <= rt) return seg[node];
    if (r < lt || rt < l) return 0;
    int mid = (l + r) >> 1;
    return max(query(node + 1, l, mid, lt, rt), query(node + ((mid - l + 1) << 1), mid + 1, r, lt, rt));
  }
 
  long long query(int l, int r) {
    return query(0, 0, N - 1, l, r);
  }
 
  void update(int idx, long long val) {
    update(0, 0, N - 1, idx, val);
  }
};


void init() {
  memset(heavy, -1, sizeof (int) * (N + 1));
  memset(head, 0, sizeof (int) * (N + 1));
  memset(pos, 0, sizeof (int) * (N + 1));
  memset(depth, 0, sizeof (int) * (N + 1));
  memset(parent, 0, sizeof (int) * (N + 1));
  edges.clear();
  for (long long i = 1; i <= N; ++i) adj[i].clear();
  currPos = -1;
}
    
long long dfsInit(int v) {
  int size = 1;
  int max_c_size = 0;
  for (int c : adj[v]) {
    if (c != parent[v]) {
      parent[c] = v, depth[c] = depth[v] + 1;
      int c_size = dfsInit(c);
      size += c_size;
      if (c_size > max_c_size)
        max_c_size = c_size, heavy[v] = c;
    }
  }
  return size;
}

void decompose(int v, int h) {
  head[v] = h, pos[v] = ++currPos;
  if (heavy[v] != -1)
      decompose(heavy[v], h);
  for (int c : adj[v]) {
      if (c != parent[v] && c != heavy[v])
          decompose(c, c);
  }
}

long long query(int a, int b, SegmentTree &seg) {
  long long res = 0;
  for (; head[a] != head[b]; b = parent[head[b]]) {
      if (depth[head[a]] > depth[head[b]]) swap(a, b);
      long long cur_heavy_path_max = seg.query(pos[head[b]], pos[b]);
      res = max(res, cur_heavy_path_max);
  }
  if (a == b) return res;
  if (depth[a] > depth[b]) swap(a, b);
  long long last_heavy_path_max = seg.query(pos[heavy[a]], pos[b]);
  res = max(res, last_heavy_path_max);
  return res;
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  long long t; cin >> t;
  while (t--) {
    cin >> N;
    init();
    for (long long i = 1; i < N; ++i) {
      long long u, v, x; cin >> u >> v >> x;
      adj[u].push_back(v);
      adj[v].push_back(u);
      edges.push_back({u, v, x});
    }
    dfsInit(1);
    decompose(1, 1);
    SegmentTree seg(N);
    for (auto it : edges) {
      if (depth[get<0>(it)] > depth[get<1>(it)]) swap(get<0>(it), get<1>(it));
      seg.update(pos[get<1>(it)], get<2>(it));
    }
    string q;
    while (1) {
      cin >> q;
      if (q == "DONE") break;
      if (q == "CHANGE") {
        int s, x; cin >> s >> x;
        --s;
        if (depth[get<0>(edges[s])] > depth[get<1>(edges[s])]) swap(get<0>(edges[s]), get<1>(edges[s]));
        seg.update(pos[get<1>(edges[s])], x);
      }
      else {
        int a, b; cin >> a >> b;
        cout << query(a, b, seg) << '\n';
      }
    }
  }
  return 0;
}
