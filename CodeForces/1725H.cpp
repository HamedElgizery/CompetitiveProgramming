#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

int MOD(int num) {
  int ret = 0;
  while (num) {
    (ret+=(num%10)%3)%=3;
    num/=10;
  }
  return ret;
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int N; cin >> N;
  int freq[3] = {};
  vector<int> A(N); for (auto &a : A) cin >> a, a = MOD(a), freq[a]++;
  if (freq[0] <= N / 2) {
    cout << 0 << endl;
    int need = N / 2 - freq[0];
    for (int i = 0; i < N; ++i) {
      if (!A[i]) {
        cout << 0;
      }
      else if (need && A[i]) {
        need--;
        cout << 0;
      }
      else {
        cout << 1;
      }
    }
  }
  else if (freq[1] + freq[2] <= N / 2) {
    cout << 2 << endl;
    int need = N / 2 - (freq[1] + freq[2]);
    for (int i = 0; i < N; ++i) {
      if (A[i] == 1 || A[i] == 2) {
        cout << 0;
      }
      else if (need) {
        cout << 0;
        need--;
      }
      else cout << 1;
    }
  }
  else cout << -1;
  return 0;
}
