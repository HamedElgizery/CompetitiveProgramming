#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int t; cin >> t;
  while (t--) {
    string S; cin >> S;
    int N = S.size();
    int needO = max(0, int(N/2 - count(S.begin(), S.end(), '(')));
    vector<int> quest;
    for (int i = 0; i < N; ++i)
      if (S[i] == '?')
        quest.push_back(i);
    for (int i = 0; i < quest.size(); ++i) {
      if (i < needO) S[quest[i]] = '(';
      else S[quest[i]] = ')';
    }
    if (quest.size() <= 1) {
      cout << "YES" << endl;
      continue;
    }
    bool ans = 0;
    for (int i = 0; i < quest.size(); ++i) {
      if (S[quest[i]] == ')') {
        if (i) swap(S[quest[i]], S[quest[i-1]]);
        else ans = 1;
        break;
      }
      if (i == quest.size() - 1) ans = 1;
    }
    int v = 0;
    for (int i = 0; i < N; ++i) {
      if (S[i] == '(') v++;
      else v--;
      if (v < 0) ans = 1;
    }
    cout << (ans ? "YES" : "NO") << endl;
  }
  return 0;
}
