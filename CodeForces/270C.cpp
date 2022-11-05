#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int N; cin >> N;
  vector<pair<int, int>> A(N);
  for (auto &a : A) cin >> a.first >> a.second;
  sort(A.begin(), A.end());
  for (int i = 0; i + 1 < N; ++i) {
    int diff = A[i+1].first - A[i].first;
    int curr = A[i].second;
    for (int j = 0; j < diff && curr > 1; ++j) {
      curr=ceil(curr/4.0);
    }
    umax(A[i+1].second, curr);
  }
  int ans = A.back().first + 1;
  while (A.back().second > 4) {
    ans++;
    A.back().second = ceil(A.back().second/4.0);
  }
  cout << ans;
  return 0;
}
