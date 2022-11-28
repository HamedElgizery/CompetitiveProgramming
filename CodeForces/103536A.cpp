#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

int N, G;
const int mxN = 8e3, mxG=3e3;
long long S[mxN];
long long dp[mxG][mxN];

void compute(int g, int l, int r, int lg, int rg) {
  if (r < l) return;
  pair<long long, int> best = {1e18, -1};
  int mid = (l + r) >> 1;
  for (int i = lg; i <= min(mid, rg); ++i) {
    long long val = (i&&g?dp[g-1][i-1]:0) + (mid-i+1)*(S[mid]-(i?S[i-1]:0));
    if (val < best.first) {
      umin(best, {val, i});
      dp[g][mid] = val;
    }
  }
  compute(g, l, mid - 1, lg, best.second);
  compute(g, mid + 1, r, best.second, rg);
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  cin >> N >> G;
  for (int i = 0; i < N; ++i) {
    cin >> S[i];
    if (i) S[i]+=S[i-1];
  }
  memset(dp, 0x3f, sizeof dp);
  for (int i = 1; i <= G; ++i)
    compute(i, 0, N - 1, 0, N - 1);
  long long ans = 1e18;
  for (int i = 1; i <= G; ++i) {
    umin(ans, dp[i][N-1]);
  }
  cout << ans;
  return 0;
}
