#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T& b) {return a = max(a, b);}
template<typename T> T umin(T& a, T& b) {return a = min(a, b);}

const int MOD = 998244353;

int solve(vector<int>&A, int sz) {
  int N = A.size();
  vector<vector<vector<int>>> dp(N,vector<vector<int>>(sz, vector<int>(sz+2, 0)));
  dp[0][A[0]%sz][sz-1] = dp[0][0][sz] = 1;
  for (int i = 1; i < N; ++i) {
    for (int j = 0; j < sz; ++j) {
      for (int k = 0; k <= sz; ++k) {
        dp[i][j][k] = (dp[i-1][(j-(A[i]%sz)+sz)%sz][k+1] + dp[i-1][j][k]) % MOD;
      }
    }
  }
  return dp.back()[0][0];
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int N; cin >> N;
  vector<int> A(N); for (auto &a : A) cin >> a;
  long long ans = N;
  for (int i = 2; i <= N; ++i) (ans += solve(A, i)) %= MOD;
  cout << ans;
  return 0;
}
