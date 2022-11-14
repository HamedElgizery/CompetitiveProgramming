#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int N; cin >> N;
  vector<pair<int, int>> A(N); 
  for (int i = 1; i <= N; ++i) {
    cin >> A[i-1].first;
    A[i-1].second = i;
  }
  sort(A.begin(), A.end());
  int cnt = 0;
  for (int i = 1; i < N; ++i) cnt += (A[i].first == A[i-1].first);
  if (cnt < 2) {
    cout << "NO";
    return 0;
  }
  cout << "YES\n";
  for (auto it : A) cout << it.second << ' ';
  cout << endl;
  for (int i = 1; i < N; ++i) if (A[i].first == A[i-1].first) {swap(A[i], A[i-1]); break;}
  for (auto it : A) cout << it.second << ' ';
  cout << endl;
  for (int i = N - 2; ~i; --i) if (A[i].first == A[i+1].first) {swap(A[i], A[i+1]); break;}
  for (auto it : A) cout << it.second << ' ';
  return 0;
}
