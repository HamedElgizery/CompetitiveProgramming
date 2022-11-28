#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

int main() {
  int t; cin >> t;
  while (t--) {
    int N, M; cin >> N >> M;
    vector<vector<int>> G(N, vector<int>(M));
    for (auto &it : G) for (auto &i : it) cin >> i;
    if ((N + M)&1^1) {
      cout << "NO\n";
      continue;
    }
    vector<vector<int>> dpMx(N, vector<int>(M, -1e9)), dpMn(N, vector<int>(M, 1e9));
    dpMx[0][0] = dpMn[0][0] = G[0][0];
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        if (i) {
          umax(dpMx[i][j], dpMx[i-1][j] + G[i][j]);
          umin(dpMn[i][j], dpMn[i-1][j] + G[i][j]);
        }
        if (j) {
          umax(dpMx[i][j], dpMx[i][j-1] + G[i][j]);
          umin(dpMn[i][j], dpMn[i][j-1] + G[i][j]);
        }
      }
    }
    if (dpMn.back().back() > 0 || dpMx.back().back() < 0) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
  }
  return 0;
}
