#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

const int MOD = 1e9+7;

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int t; cin >> t;
  while (t--) {
    int N; cin >> N;
    vector<int> A(N), pos(N);
    for (int i = 0; i < N; ++i) cin >> A[i], pos[A[i]] = i;
    int curr = 1;
    long long ans = 1;
    int l = pos[0], r = pos[0];
    while (curr < N) {
      if (pos[curr] < l) l = pos[curr];
      else r = pos[curr];
      int add = 0;
      int ncurr = curr+1;
      while (ncurr < N && l <= pos[ncurr] && pos[ncurr] <= r) {
        ncurr++;
        add++;
      }
      for (int i = 0, j = r - l - curr; i < add; ++i, --j) {
        (ans *= j) %= MOD;
      }
      curr = ncurr;
    }
    cout << ans << endl;
  }
  return 0;
}
