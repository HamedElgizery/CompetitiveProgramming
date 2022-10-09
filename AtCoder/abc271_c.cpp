#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int N; cin >> N;
  int toUse = 0;
  set<int> st;
  for (int i = 0; i < N; ++i) {
    int num; cin >> num;
    if (st.find(num) == st.end()) st.insert(num);
    else toUse++;
  }
  int ans = 0;
  while (!(st.empty() && !toUse)) {
    auto it = st.find(ans + 1);
    if (it != st.end()) {
      ans++;
      st.erase(it);
    }
    else {
      if (toUse + st.size() < 2) break;
      for (int i = 0; i < 2; ++i) {
        if (toUse) toUse--;
        else st.erase(prev(st.end()));
      }
      st.insert(ans + 1);
    }
  }
  cout << ans;
  return 0;
}
