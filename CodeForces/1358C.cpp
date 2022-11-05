#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int t; cin >> t;
  while (t--) {
    long long x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << 1 + (x2 - x1) * (y2 - y1) << endl;
  }
  return 0;
}
