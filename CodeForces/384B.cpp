#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int N, M, K; cin >> N >> M >> K;
  cout << (M*(M-1)>>1) << endl;
  if (K) {
    for (int i = M; i; --i) {
      for (int j = i - 1; j; --j) {
        cout << i << ' ' << j << endl;
      }
    }
  }
  else {
    for (int i = 1; i <= M; ++i) {
      for (int j = i + 1; j <= M; ++j) {
        cout << i << ' ' << j << endl;
      }
    }
  }
  return 0;
}
