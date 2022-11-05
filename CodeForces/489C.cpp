#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int m, s;
  cin >> m >> s;
  if (!s) {
    if (m > 1) cout << -1 << ' ' << -1;
    else cout << 0 << ' ' << 0;
    return 0;
  }
  string ans = string(m, '0');
  ans[0] = '1';
  --s;
  int j = m - 1;
  for (int i = 0; i < s; ++i) {
    if (ans[j] == '9') --j;
    if (j<0) {
      cout << -1 << ' ' << -1;
      return 0;
    }
    ans[j]++;
  }
  cout << ans << ' ';
  ans = string(m, '0');
  ++s;
  j = 0;
  for (int i = 0; i < s; ++i) {
    if (ans[j] == '9') ++j;
    if (j>=m) {
      cout << -1 << ' ' << -1;
      return 0;
    }
    ans[j]++;
  }
  cout << ans;
  return 0;
}
