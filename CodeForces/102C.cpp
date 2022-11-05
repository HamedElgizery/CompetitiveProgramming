#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  string S; cin >> S;
  set<pair<int, char>> st;
  int K; cin >> K;
  for (char i = 'a'; i <= 'z'; ++i) {
    int cnt = 0;
    for (auto it : S) cnt += (it == i);
    if (cnt) st.insert({cnt, i});
  }
  set<char> del;
  while (!st.empty()) {
    K -= st.begin()->first;
    if (K >= 0) {
      del.insert(st.begin()->second);
      st.erase(st.begin());
    }
    else break;
  }
  cout << st.size() << endl;
  for (auto it : S) if (del.find(it) == del.end()) cout << it;
  return 0;
}
