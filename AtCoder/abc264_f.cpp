#include <bits/stdc++.h>
#define inf 1e18
using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

const int mxN = 2000;
long long dp[mxN][mxN][2][2];

const int di[] = {1, 0};
const int dj[] = {0, 1};

void init() {
  for (int i = 0; i < mxN; ++i)
    for (int j = 0; j < mxN; ++j)
      for (int k = 0; k < 2; ++k)
        for (int z = 0; z < 2; ++z)
          dp[i][j][k][z] = inf;
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int H, W; cin >> H >> W;
  vector<int> R(H); for (auto &it : R) cin >> it;
  vector<int> C(W); for (auto &it : C) cin >> it;
  vector<vector<int>> grid(H, vector<int>(W));
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      char c; cin >> c;
      grid[i][j] = c - '0';
    }
  }
  auto solve = [&]() -> long long {
    init();
    for (int i = 0; i < 2; ++i) {
      int j = grid[0][0] ^ i;
      dp[0][0][0][j] = R[0] * i + C[0] * j;
      dp[0][0][1][i] = R[0] * i + C[0] * j;
    }
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        for (int k = 0; k < 2; ++k) {
          for (int z = 0; z < 2; ++z) {
            int ni = i + di[k], nj = j + dj[k];
            if (ni >= H || nj >= W) continue;
            int c;
            if (k) c = C[j+1];
            else c = R[i+1];
            umin(dp[ni][nj][k][z], dp[i][j][k][z] + (z^grid[ni][nj]) * c);
            umin(dp[ni][nj][1-k][z^grid[ni][nj]], dp[i][j][k][z] + (z^grid[ni][nj]) * c);
          }
        }
      }
    }
    long long ret = inf;
    for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) umin(ret, dp[H-1][W-1][i][j]);
    return ret;
  };
  long long ans = solve();
  for (int i = 0; i < H; ++i)
    for (int j = 0; j < W; ++j)
      grid[i][j] ^= 1;
  umin(ans, solve());
  cout << ans;
  return 0;
}
