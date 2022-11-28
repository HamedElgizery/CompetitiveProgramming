#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int N, K; cin >> N >> K;
  vector<vector<int>> A(N, vector<int>(K));
  map<vector<int>, int> idx;
  {
    int i = 0;
    for (auto &a : A) {
      for (auto &it : a) cin >> it;
      idx[a] = i++;
    }
  }
  vector<long long> cnt(N, 0);
  vector<int> tmp(K);
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      if (i == j) continue;
      for (int x = 0; x < K; ++x) {
        tmp[x] = ((-(A[i][x] + A[j][x])) % 3 + 3) % 3;
      }
      if (idx.find(tmp) != idx.end()) {
        cnt[idx[tmp]]++;
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < N; ++i) {
    ans += (cnt[i] * (cnt[i]-1)) >> 1;
  }
  cout << ans;
  return 0;
}
