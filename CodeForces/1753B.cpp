#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

const int mxN = 5e5+1;
int freq[mxN];

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int N, X; cin >> N >> X;
  vector<int> A(N); for (auto &a : A) cin >> a, freq[a]++;
  bool ans = 1;
  for (int i = 1; i < X; ++i) {
    freq[i+1]+=freq[i]/(i+1);
    freq[i]%=(i+1);
    ans &= !(freq[i]);
  }
  cout << (ans ? "YES" : "NO");
  return 0;
}
