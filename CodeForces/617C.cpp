#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

long long sq(long long n) {
  return n * n;
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int N, X1, Y1, X2, Y2; cin >> N >> X1 >> Y1 >> X2 >> Y2;
  vector<pair<int, int>> A(N); for (auto &a : A) cin >> a.first >> a.second;
  vector<pair<long long, long long>> dist;
  for (auto it : A) {
    pair<long long, long long> val;
    val.first = sq(X1 - it.first) + sq(Y1 - it.second);
    val.second = sq(X2 - it.first) + sq(Y2 - it.second);
    dist.push_back(val);
  }
  sort(dist.begin(), dist.end());
  long long ans = LLONG_MAX;
  long long r2 = 0;
  for (int i = N - 1; ~i; --i) {
    if (!(i+1<N && dist[i+1].first == dist[i].first)) 
    umin(ans, r2 + dist[i].first);
    umax(r2, dist[i].second);
  }
  umin(ans, r2);
  cout << ans;
  return 0;
}
