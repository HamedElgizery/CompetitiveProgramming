#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int t; cin >> t;
  while (t--) {
    int N; cin >> N;
    vector<int> A(N); for (auto &a : A) cin >> a;
    sort(A.begin(), A.end());
    int ans = 0;
    for (int i = N - 1; i > 1; --i) {
      umax(ans, 2 * A[i] - A[0] - A[i - 1]);
    }
    for (int i = 0; i + 1 < N; ++i) {
      umax(ans, A[N - 1] + A[i + 1] - 2 * A[i]);
    }
    cout << ans << endl;
  }
  return 0;
}
