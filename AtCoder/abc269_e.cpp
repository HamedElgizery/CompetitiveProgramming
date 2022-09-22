#include <bits/stdc++.h>

using namespace std;

#define inf 1e18
template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int N; cin >> N;
  int R, C;
  // ROW
  int l = 1, r = N;
  while (l < r) {
    int mid = (l + r) >> 1;
    cout << "? ";
    cout << 1 << ' ' << mid << ' ' << 1 << ' ' << N << endl;
    int res; cin >> res;
    if (res < mid) r = mid;
    else l = mid + 1;
  }
  R = r;
  // COL 
  l = 1, r = N;
  while (l < r) {
    int mid = (l + r) >> 1;
    cout << "? ";
    cout << 1 << ' ' << N << ' ' << 1 << ' ' << mid << endl;
    int res; cin >> res;
    if (res < mid) r = mid;
    else l = mid + 1;
  }
  C = r;
  cout << "! " << R << ' ' << C << endl;
  return 0;
}
