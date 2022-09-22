#include <bits/stdc++.h>

using namespace std;

#define inf 1e18
template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T; cin >> T;
  while (T--) {
    set<int> list; 
    set<pair<int, int>> badPair;
    int N; cin >> N;
    vector<int> A(N); for (auto &a : A) cin >> a;
    for (int i = 0; i < N; ++i) list.insert(i);
    for (int i = 0; i < N; ++i)
      if (__gcd(A[i], A[(i+1)%N]) == 1) 
        badPair.insert({i, (i+1)%N});
    vector<int> ans;
    int curr = 0;
    while (!badPair.empty()) {
      auto it = badPair.lower_bound({curr, 0});
      if (it == badPair.end()) {
        curr = 0;
        it = badPair.lower_bound({curr, 0});
        if (it == badPair.end()) break;
      }
      pair<int, int> bad = *it;
      list.erase(list.find(it->second));
      int next;
      if (list.upper_bound(it->first) == list.end()) next = *list.begin();
      else next = *list.upper_bound(it->first);
      badPair.erase(it);
      auto poss = badPair.lower_bound({bad.second, 0});
      if (poss != badPair.end() && poss->first == bad.second) badPair.erase(badPair.lower_bound({bad.second, 0}));
      if (__gcd(A[bad.first], A[next]) == 1 && list.find(next) != list.end()) badPair.insert({bad.first, next});
      ans.push_back(bad.second);
      curr=(bad.second+1)%N;
    }
    cout << ans.size();
    for (auto it : ans) cout << ' ' << it+1;
    cout << endl;
  }
  return 0;
}
