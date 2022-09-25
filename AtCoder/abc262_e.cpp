#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T& b) {return a = max(a, b);}
template<typename T> T umin(T& a, T& b) {return a = min(a, b);}

const int MOD = 998244353;

long long FP(long long x, long long y) {
  long long ret = 1;
  while (y) {
    if (y&1) (ret*=x)%=MOD;
    (x*=x)%=MOD;
    y >>= 1;
  }
  return ret;
}

long long MODINV(int x) {
  return FP(x, MOD - 2);
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int N, M, K; cin >> N >> M >> K;
  vector<int> deg(N, 0);
  for (int i = 0; i < M; ++i) {
    int u, v; cin >> u >> v;
    deg[--u]++; deg[--v]++;
  }
  int odd = 0, even = 0;
  for (auto it : deg) {
    if (it&1) odd++;
    else even++;
  }
  //0 -> odd, 1 -> even
  array<vector<int>, 2> ncr;
  ncr[0].resize(K+1);
  ncr[1].resize(K+1);
  ncr[0][0] = ncr[1][0] = 1;
  for (int i = 1; i <= K; ++i) {
    ncr[0][i]=(((ncr[0][i-1]*MODINV(i))%MOD)*(odd-i+1))%MOD;
    ncr[1][i]=(((ncr[1][i-1]*MODINV(i))%MOD)*(even-i+1))%MOD;
  }
  auto NCR = [&](int x, int r) -> long long {
    return ncr[x][r];
  };
  long long ans = 0;
  for (int i = 0; i <= K; i+=2) (ans+=NCR(0,i)*NCR(1,K-i))%=MOD;
  cout << ans;
  return 0;
}
