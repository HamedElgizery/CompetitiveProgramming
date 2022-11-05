#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

const long double EPS = 1e-9;

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int a, b; cin >> a >> b;
  vector<pair<int, int>> valid;
  for (int x = 1; x * x < a * a; ++x) {
    int y = sqrt(a * a - x * x);
    if (y * y != a * a - x * x) continue;
    valid.push_back({x, y});
  }
  for (auto [x, y] : valid) {
    long double ceta = atan(y*1.0/x) + acos(-1)/2;
    long double x2 = b*cos(ceta);
    long double y2 = b*sin(ceta);
    if (abs(x2 - round(x2)) > EPS || abs(y2 - round(y2)) > EPS || abs(x2) <= EPS || abs(y2) <= EPS || round(x2) == x || round(y2) == y) continue;
    cout << "YES\n";
    cout << 0 << ' ' << 0 << endl;
    cout << x << ' ' << y << endl;
    cout << round(x2) << ' ' << round(y2) << endl;
    return 0;
  }
  cout << "NO";
  return 0;
}
