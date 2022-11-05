#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int N, K; cin >> N >> K;
  int UP = N, DOWN = 1;
  for (int i = 1; i <= K; ++i) {
    if (i&1) cout << UP-- << ' '; 
    else cout << DOWN++ << ' ';
  }
  if (K&1^1) {
    for (int i = DOWN; i <= UP; ++i) cout << i << ' ';
  }
  else {
    for (int i = UP; i >= DOWN; --i) cout << i << ' ';
  }
  return 0;
}
