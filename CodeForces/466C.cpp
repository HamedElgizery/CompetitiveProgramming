#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int N; cin >> N;
  vector<long long> A(N); for (auto &a : A) cin >> a;
  map<long long, int> freq;
  for (int i = 1; i < N; ++i) A[i] += A[i-1], freq[A[i]]++;
  freq[A[0]]++;
  freq[A.back()]--;
  long long ans = 0;
  for (int i = 0; i+2 < N; ++i) {
    freq[A[i]]--;
    if (A.back() != A[i]*3) continue;
    ans += freq[A[i]*2];
  }
  cout << ans;
  return 0;
}
