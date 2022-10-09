#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

const int mxN = 20;
int A[mxN][mxN];

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int N; cin >> N;
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      cin >> A[i][j];
  map<pair<int, int>, int> mp;
  for (int msk = 0; msk < (1<<(N-1)) ; ++msk) {
    int val = A[0][0];
    int ii = 0, jj = 0;
    for (int i = 0; i < N-1; ++i) {
      if (msk&(1<<i)) ii++;
      else jj++;
      val ^= A[ii][jj];
    }
    mp[make_pair(__builtin_popcount(msk), val)]++;
  }
  long long ans = 0;
  for (int msk = 0; msk < (1<<(N-1)); ++msk) {
    int cnt = __builtin_popcount(msk);
    int val = A[N-1][N-1];
    int ii = N - 1, jj = N - 1;
    for (int i = 0; i+1 < N-1; ++i) {
      if (msk&(1<<i)) ii--;
      else jj--;
      val ^= A[ii][jj];
    }
    ans+=mp[make_pair(N - 1 - cnt, val)];
  }
  cout << ans;
  return 0;
}
