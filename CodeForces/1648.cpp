#include <bits/stdc++.h>

using namespace std;

int32_t main() {
  cin.tie(0)->sync_with_stdio(false);
  int T; cin >> T;
  while (T--) {
    int N, C; cin >> N >> C;
    vector<int> freq(C + 1, 0);
    for (int i = 0; i < N; ++i) {
      int num; cin >> num;
      freq[num]++;
    }
    vector<int> A, notA;
    for (int i = 1; i <= C; ++i) {
      if (freq[i]) A.push_back(i);
      else notA.push_back(i);
    }
    for (int i = 1; i <= C; ++i) freq[i] += freq[i - 1];
    auto range = [&](int l, int r) {
      return freq[min(r, C)] - freq[l - 1];
    };
    bool ans = 1;
    for (auto r : notA) {
      for (auto y : A) {
        int64_t mn = r * 1ll * y;
        if (mn > C) break;
        if (range(mn, mn + y - 1)) ans = 0;
      }
    }
    cout << (ans ? "Yes\n" : "No\n");
  }
  return 0;
}
