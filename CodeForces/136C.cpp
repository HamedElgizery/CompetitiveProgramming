#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int N; cin >> N;
  vector<int> A(N); for (auto &a : A) cin >> a;
  sort(A.begin(), A.end());
  int cnt = count(A.begin(), A.end(), 1);
  for (int i = 0; i < N; ++i) {
    if (i == N - 1 && cnt == N) {
      cout << 2;
    }
    else if (i == 0) cout << 1;
    else cout << A[i-1];
    cout << ' ';
  }
  return 0;
}
