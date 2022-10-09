#include <bits/stdc++.h>

using namespace std;

long long ok(long long mid, vector<long long> &A) {
  int N = A.size();
  long long eaten = 0;
  for (int i = 0; i < N; ++i) {
    long long vis = (mid / N) + bool(((mid-1) % N >= i) && mid%N);
    eaten += min(vis, A[i]);
  }
  return eaten;
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  long long N, K; cin >> N >> K;
  vector<long long> A(N); for (auto &a : A) cin >> a;
  long long l = 1, r = K * N;
  while (l < r) {
    long long mid = (l + r) >> 1;
    if (ok(mid, A) >= K) r = mid;
    else l = mid + 1;
  }
  cerr << l << endl;
  for (int i = 0; i < N; ++i) {
    if (i) cout << ' ';
    cout <<  max(0ll, A[i] - (l / N) - bool(((l-1)%N >= i) && l%N));
  }
  return 0;
}
