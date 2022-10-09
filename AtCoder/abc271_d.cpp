#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int N, S; cin >> N >> S;
  vector<pair<int, int>> A(N); for (auto &a : A) cin >> a.first >> a.second;
  vector<vector<int>> dp(N, vector<int>(S+1, 0));
  if (S - A.back().first >= 0) dp.back()[S-A.back().first] = 1;
  if (S - A.back().second >= 0) dp.back()[S-A.back().second] = 2;
  for (int i = N - 2; ~i; --i) {
    for (int j = 0; j <= S; ++j) {
      if (j+A[i].first <= S && dp[i+1][j+A[i].first]) dp[i][j] = 1;
      if (j+A[i].second <= S && dp[i+1][j+A[i].second]) dp[i][j] = 2;
    }
  }
  cout << (dp[0][0] ? "Yes" : "No") << endl;
  if (dp[0][0]) {
    int cs = 0;
    for (int i = 0; i < N; ++i) {
      if (dp[i][cs] == 1) {
        cout << 'H';
        cs += A[i].first;
      }
      else {
        cout << 'T';
        cs += A[i].second;
      }
    }
  }
  return 0;
}
