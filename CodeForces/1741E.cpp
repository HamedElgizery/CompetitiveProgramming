#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

const int mxN = 5e5+1;
int freq[mxN];

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int t; cin >> t;
  while (t--) {
    int N; cin >> N;
    vector<vector<int>> seg(N);
    vector<int> A(N); 
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
      if (i >= A[i])
      seg[i - A[i]].push_back(i);
    }
    vector<bool> dp(N+1, 0);
    dp.back() = 1; 
    for (int i = N - 1; ~i; --i) {
      if (i + A[i] + 1 <= N && dp[i+A[i]+1]) dp[i] = 1;
      for (auto it : seg[i]) if(dp[it+1]) dp[i] = 1;
    }
    cout << (dp[0] ? "YES" : "NO") << "\n";
  }
  return 0;
}
