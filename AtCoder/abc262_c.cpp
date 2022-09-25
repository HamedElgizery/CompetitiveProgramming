#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T& b) {return a = max(a, b);}
template<typename T> T umin(T& a, T& b) {return a = min(a, b);}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int N; cin >> N;
  vector<int> A(N); for (auto &a : A) cin >> a, --a;
  long long ans = 0, inPlace = 0;
  for (int i = 0; i < N; ++i) {
    if (A[i] == i) ans += inPlace, inPlace++;
    else if (A[A[i]] == i && A[i] > i) ans++;
  }
  cout << ans;
  return 0;
}
