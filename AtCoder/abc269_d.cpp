#include <bits/stdc++.h>

using namespace std;

#define inf 1e18
template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

const int di[] = {-1, -1, 0, 0, 1, 1};
const int dj[] = {-1, 0, -1, 1, 0, 1};
const int mxN = 2001;
set<pair<int, int>> P;
bool vis[mxN][mxN];

void dfs(int i, int j) {
  vis[i][j] = 1;
  for (int d = 0; d < 6; ++d) {
    int ni = i + di[d], nj = j + dj[d];
    if (P.find({ni, nj}) == P.end()) continue;
    if (vis[ni][nj]) continue;
    dfs(ni, nj);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int N; cin >> N; 
  for (int i = 0; i < N; ++i) {
    pair<int, int> p; cin >> p.first >> p.second;
    p.first += 1000;
    p.second += 1000;
    P.insert(p);
  }
  int ans = 0;
  for (auto it : P)
    if (!vis[it.first][it.second])
      dfs(it.first, it.second), ans++;
  cout << ans;
  return 0;
}
