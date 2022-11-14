#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  long long N, K; cin >> N >> K;
  vector<long long> A(N); for (auto &a : A) cin >> a;
  vector<long long> sum(N, 0);
  map<long long, long long> mp;
  for (int i = N - 1; ~i; --i) {
    sum[i] += mp[A[i] * K];
    mp[A[i]]++;
  }
  //for (auto it : sum) cout << it << ' ';
  //cout << endl;
  mp.clear();
  long long ans = 0;
  for (int i = N-1; ~i; --i) {
    ans += mp[A[i] * K];
    mp[A[i]]+=sum[i];
  }
  cout << ans;
  return 0;
}
