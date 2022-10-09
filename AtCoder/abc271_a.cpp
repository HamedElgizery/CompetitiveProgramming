#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  map<int, char> mp;
  for (int i = 0; i < 10; ++i) mp[i] = i + '0';
  for (int i = 10; i <= 15; ++i) mp[i] = i - 10 + 'A';
  int N; cin >> N;
  string ans;
  while (N) ans += mp[N%16], N/=16;
  while (ans.size() < 2) ans += '0';
  reverse(ans.begin(), ans.end());
  cout << ans;
  return 0;
}
