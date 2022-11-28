#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

vector<int> di, dj;
int N, M;
const int mxN = 50;
vector<string> G(mxN);
bool vis[mxN][mxN];

int dfs(int i, int j) {
  if (vis[i][j]) return 0;
  vis[i][j] = 1;
  int ret = 1;
  for (int d = 0; d < 8; ++d) {
    int ii = i + di[d], jj = j + dj[d];
    if (!(0 <= ii && ii < N && 0 <= jj && jj < M) || G[ii][jj] == '.') continue;
    ret += dfs(ii, jj);
  }
  return ret;
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int t; cin >> t;
  while (t--) {
    memset(vis, 0, sizeof vis);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) cin >> G[i];
    bool ans = 1;
    di = {0, 1, 0, -1, 1, 1, -1, -1};
    dj = {-1, 0, 1, 0, 1, -1, 1, -1};
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        if (!vis[i][j] && G[i][j] == '*') ans&=(dfs(i, j)==3);
      }
    }
    if (!ans) {
      cout << "NO\n";
      continue;
    }
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        if (G[i][j] == '.') continue;
        if (i >= 2) {
          ans&=!(G[i-1][j]==G[i-2][j]&&G[i-1][j]=='*');
        }
        if (j >= 2) {
          ans&=!(G[i][j-1]==G[i][j-2]&&G[i][j-1]=='*');
        }
        if (i >= 2 && j >= 2) {
          ans&=!(G[i-1][j-1]==G[i-2][j-2]&&G[i-1][j-1]=='*');
        }
        if (i >= 2 && j + 2 < M) {
          ans&=!(G[i-1][j+1]==G[i-2][j+2]&&G[i-1][j+1]=='*');
        }
        int cnt = 0;
        for (int d = 0; d < 8; ++d) {
          int ii = di[d] + i, jj = dj[d] + j;
          if (!(0 <= ii && ii < N && 0 <= jj && jj < M) || G[ii][jj] == '.') continue;
          cnt++;
        }
        ans&=(cnt==2);
      }
    }
    if (!ans) cout << "NO\n";
    else cout << "YES\n";
  }
  return 0;
}
