#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

const int mxN = 1e5+1;
vector<int> adj[mxN];

pair<int, int> dfs(int node) {
  int ret = 0, ret2 = 0;
  for (auto it : adj[node]) {
    pair<int, int> val = dfs(it);
    ret += max(val.first, val.second);
    umax(ret2, val.second);
  }
  return make_pair(ret, ret2+1);
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int N; cin >> N;
  for (int i = 2; i <= N; ++i) {
    int p; cin >> p;
    adj[p].push_back(i);
  }
  pair<int, int> ans = dfs(1);
  cout << max(ans.first, ans.second);
  return 0;
}
