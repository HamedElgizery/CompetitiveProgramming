#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

long long ans[7];
const int mxN = 1e6+10;
vector<int> adj[mxN];
bool vis[mxN];
map<string, int> mp;

struct segtree {
  int N;
  vector<array<int, 7> > seg;
  vector<int> lazy;
  segtree(int N) : N(N) {
    seg.assign(N<<1, array<int, 7>());
    lazy.assign(N<<1, -1);
  }

  void propagate(int node, int l, int r) {
    if (~lazy[node]) {
      int mid = (l + r) >> 1;
      lazy[node + 1] = lazy[node];
      lazy[node + ((mid - l + 1) << 1)] = lazy[node];
      for (int i = 0; i < 7; ++i) {
        if (i != lazy[node]) {
          seg[node+1][i]=seg[node+((mid-l+1)<<1)][i]=0;
        }
        else {
          seg[node+1][i]=mid-l+1;
          seg[node+((mid-l+1)<<1)][i]=r-mid;
        }
      }
      lazy[node] = -1;
    }
  }
  void update(int node, int l, int r, int lt, int rt, int col) {
    if (lt <= l && r <= rt) {
      int add = r-l+1 - seg[node][col];
      for (int i = 0; i < 7; ++i)
          seg[node][i] = 0;
      seg[node][col] = r-l+1;
      ans[col]+=add;
      lazy[node]=col;
      return;
    }
    if (r < lt || rt < l) return;
    propagate(node, l, r);
    int mid = (l + r) >> 1;
    update(node + 1, l, mid, lt, rt, col);
    update(node + ((mid - l + 1) << 1), mid + 1, r, lt, rt, col);
    for (int i = 0; i < 7; ++i)
      seg[node][i]=seg[node+1][i]+seg[node+((mid-l+1)<<1)][i];
  }

  void update(int l, int r, int col) {
    update(0, 0, N - 1, l, r, col);
  }
};

int head[mxN], heavy[mxN], depth[mxN], parent[mxN], pos[mxN], currPos = 0;

void dfsInit(int node, int N) {
  vector<int> mxSize(N, 0), sz(N, 1);
  stack<int> st;
  st.push(node);
  while (!st.empty()) {
    node = st.top();
    vis[node] = 1;
    bool flag = 1;
    for (auto it : adj[node]) {
      if (vis[it]) continue;
      if (it == parent[node]) continue;
      st.push(it);
      depth[it] = depth[node] + 1;
      parent[it] = node;
      flag=0;
    }
    if (!flag) continue;
    sz[parent[node]] += sz[node];
    if (mxSize[parent[node]] < sz[node]) {
      umax(mxSize[parent[node]], sz[node]);
      if (parent[node] != node)
      heavy[parent[node]] = node;
    }
    st.pop();
  }
}

void decompose(int node, int h) {
  stack<pair<int, int>> st;
  st.push({node, h});
  while (!st.empty()) {
    node = st.top().first;
    h = st.top().second;
    st.pop();
    pos[node] = currPos++;
    head[node] = h;
    for (auto it : adj[node]) {
      if (it == parent[node] || it == heavy[node]) continue;
      st.push({it, it});
    }
    if (~heavy[node]) st.push({heavy[node], h});
  }
}

void query(int a, int b, int color, segtree &seg) {
  for (; head[a] != head[b]; b = parent[head[b]]) {
    if (depth[head[a]] > depth[head[b]]) swap(a, b);
    seg.update(pos[head[b]], pos[b], color);
  }
  if (a == b) return;
  if (depth[a] > depth[b]) swap(a, b);
  seg.update(pos[a]+1, pos[b], color);
}

int main() {
  vector<string> order;
  order.push_back("red");
  order.push_back("orange");
  order.push_back("yellow");
  order.push_back("green");
  order.push_back("blue");
  order.push_back("indigo");
  order.push_back("violet");
  for (int i = 0; i < 7; ++i) mp[order[i]] = i;
  int t; scanf("%d", &t);
  while (t--) {
    int N; scanf("%d", &N);
    memset(ans, 0, sizeof ans);
    memset(heavy, -1, sizeof (int) * N);
    memset(vis, 0, sizeof (bool) * N);
    currPos = 0;
    segtree seg(N);
    for (int i = 1; i < N; ++i) {
      int u, v; scanf("%d%d", &u, &v);
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    dfsInit(0, N);
    decompose(0, 0);
    int Q; scanf("%d", &Q);
    char color[10];
    while (Q--) {
      int a, b;
      scanf("%d%d%s", &a, &b, color);
      query(a, b, mp[color], seg);
    }
    for (int i = 0; i < 7; ++i) {
      printf(order[i].c_str());
      printf(" %lld\n", ans[i]);
    }
    if (t) puts("");
    for (int i = 0; i < N; ++i) adj[i].clear();
  }
  return 0;
}
