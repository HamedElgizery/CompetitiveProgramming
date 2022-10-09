#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int N; cin >> N;
  vector<array<int64_t, 3>> A(N); 
  for (int i = 0; i < N; ++i) {
    string s; cin >> s;
    int64_t cntX = 0, sum = 0, partAns = 0;
    for (int i = s.size() - 1; ~i; --i) {
      char it = s[i];
      if (it == 'X') cntX++, partAns += sum;
      else sum += it - '0';
    }
    A[i] = {cntX, sum, partAns};
  }
  sort(A.begin(), A.end(), [](array<int64_t, 3> &first, array<int64_t, 3> &second) {
    return first[0] * second[1] > first[1] * second[0];
  });
  long long ans = 0;
  long long sumSuff = 0;
  for (int i = N - 1; ~i; --i) {
    ans += A[i][0] * sumSuff + A[i][2];
    sumSuff += A[i][1];
  }
  cout << ans;
  return 0;
}
