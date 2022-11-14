#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int N; cin >> N;
  string S; cin >> S;
  string ans = S;
  for (int i = 0; i < N; ++i) {
    S.push_back(S[0]);
    S.erase(S.begin());
    int add = 10 - S[0] + '0';
    for (int j = 0; j < N; ++j) {
      int curr = (S[j] + add - '0') % 10;
      S[j] = curr + '0';
    }
    umin(ans, S);
  }
  cout << ans;
  return 0;
}
