#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

pair<bool, string> generate(string S, int idx, char mx) {
  int N = S.size();
  bool st = 0;
  while (S[idx] < mx) {
    S[idx]++;
    if (idx && S[idx] == S[idx-1] || idx-1 && S[idx] == S[idx-2]) continue;
    st = 1;
    break;
  }
  if (!st) return {0, S};
  for (int i = idx + 1; i < N; ++i) {
    S[i] = 'a';
    if (i && S[i] == S[i-1] || i-1 && S[i] == S[i-2]) {
      st = 0;
      while (S[i] < mx) {
        S[i]++;
        if (i && S[i] == S[i-1] || i-1 && S[i] == S[i-2]) continue;
        st = 1;
        break;
      }
      if (!st) return {0, S};
    }
  }
  return {1, S};
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int N, P; cin >> N >> P;
  char mx = 'a' + P - 1;
  string S; cin >> S;
  for (int i = N - 1; i >= 0; --i) {
    if (S[i] < mx) {
      pair<bool, string> ans = generate(S, i, mx);
      if (ans.first) {
        cout << ans.second;
        return 0;
      }
    }
  }
  cout << "NO";
  return 0;
}
