#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

const int MOD = 998244353;

long long rem(long long b, vector<pair<int, int>> &a) {
  long long ret = 0;
  for (int msk = 1; msk < (1 << a.size()); ++msk) {
    long long val = 1;
    for (int j = 0; j < a.size(); ++j) {
      if (msk & (1 << j)) val *= a[j].second;
    }
    if (__builtin_popcount(msk)&1) ret += b / val;
    else ret -= b / val;
  }
  return ret;
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int t; cin >> t;
  while (t--) {
    int N, M; cin >> N >> M;
    vector<long long> A(N); for (auto &a : A) cin >> a;
    multiset<int> primes;
    {
      int a = A[0];
      for (long long i = 2; i * i <= a; ++i) {
        if (a % i == 0) {
          while (a % i == 0) primes.insert(i), a/=i;
        }
      }
      if (a > 1) primes.insert(a);
    }
    vector<long long> dp(N, 0);
    dp[0] = 1;
    vector<pair<int, int>> tmps;
    for (int i = 1; i < N; ++i) {
      if (A[i-1] % A[i]) break; // so we end with zero
      int curr = A[i-1]/A[i];
      for (auto it : primes) {
        int cnt = 0;
        while (curr % it == 0) {
          curr/=it;
          cnt++;
        }
        if (cnt) tmps.push_back({cnt, it});
      }
      for (auto it : tmps) for (int i = 0; i < it.first; ++i) primes.erase(primes.find(it.second));
      //mid * A[i] <= M
      // mid <= M / A[i]
      // mid = floor(M / A[i])
      long long l = M / A[i];
      long long val = l - rem(l, tmps);
      (dp[i] = dp[i-1] * val) %= MOD;
      tmps.clear();
    }
    cout << dp.back() << endl;
  }
  return 0;
}
