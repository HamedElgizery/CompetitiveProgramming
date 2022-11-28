#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int t; cin >> t;
  while (t--) {
    int N; cin >> N;
    vector<int> A(N), B(N);
    for (auto &a : A) cin >> a;
    for (auto &b : B) cin >> b;
    unordered_map<int, int> freq;
    int ans = 0;
    for (int i = 29; ~i; --i) {
      int msk = ans|(1<<i);
      bool ok = 1;
      freq.clear();
      for (auto b : B)
        freq[b&msk]++;
      for (auto a : A) {
        if (!freq[a&msk^msk]) {
          ok = 0; 
          break;

        }
        freq[a&msk^msk]--;
      }
      if (ok) ans = msk;
    }
    cout << ans << endl;
  }
  return 0;
}
