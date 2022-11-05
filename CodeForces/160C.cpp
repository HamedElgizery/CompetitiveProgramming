#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  long long N, K; cin >> N >> K;
  map<int, int> freq;
  vector<int> A(N); for (auto &a : A) cin >> a, freq[a]++;
  sort(A.begin(), A.end());
  --K;
  for (auto [a, b] : freq) {
    if (b * N <= K) {
      K -= b * N;
    }
    else {
      K /= b;
      cout << a << ' ' << A[K%N];
      break;
    }
  }
  return 0;
}
