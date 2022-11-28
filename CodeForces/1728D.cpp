#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

string S;
const int mxN = 2000;
int dp[mxN][mxN][2];
//0 draw
//1 Alice
//2 Bob
int mem(int l, int r, int prev = 0) {
  if (l + 1 == r) {
    if (S[l] == S[r]) return 0;
    else return 1;
  }
  auto &ret = dp[l][r][prev];
  if (~ret) return ret;
  if ((r-l+1)&1^1) {
    int left = mem(l+1, r, 0);
    int right = mem(l, r-1, 1);
    if (left == 1 || right == 1)
      ret = 1;
    else if (left == 0 || right == 0)
      ret = 0;
    else
      ret = 2;
  }
  else {
    int left = mem(l+1, r);
    int right = mem(l, r-1);
    if (left == 2 || right == 2)
      ret = 2;
    else if (left == 0) {
      if (S[l] < S[prev?r+1:l-1]) ret = 1;
      if (S[l] > S[prev?r+1:l-1]) ret = 2;
      if (S[l] == S[prev?r+1:l-1]) ret = 0;
    }
    else if (right == 0) {
      if (S[r] < S[prev?r+1:l-1]) ret = 1;
      if (S[r] > S[prev?r+1:l-1]) ret = 2;
      if (S[r] == S[prev?r+1:l-1]) ret = 0;
    }
    else ret = 1;
  }
  return ret;
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int t; cin >> t;
  while (t--) {
    cin >> S;
    int N = S.size();
    for (int i = 0; i < N; ++i) {
      for (int j = i; j < N; ++j) {
        for (int k = 0; k < 2; ++k)
          dp[i][j][k] = -1;
      }
    }
    int ans = mem(0, S.size() - 1);
    if (ans == 0) cout << "Draw\n";
    if (ans == 1) cout << "Alice\n";
    if (ans == 2) cout << "Bob\n";
  }
  return 0;
}
