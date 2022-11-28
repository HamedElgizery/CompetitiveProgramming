#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int t; cin >> t;
  while (t--) {
    int N, Q; cin >> N >> Q;
    vector<int> A(N); for (auto &a : A) cin >> a;
    int ll, rr; cin >> ll >> rr;
    vector<vector<bool>> prefX(30, vector<bool>(N, 0));
    vector<long long> pref(N, 0);
    long long sum = 0, _xor = 0;
    for (int i = 0; i < N; ++i) {
      _xor^=A[i];
      sum+=A[i];
      pref[i]=A[i];
      if (i) pref[i]+=pref[i-1];
      for (int j = 0; j < 30; ++j) {
        prefX[j][i]=(A[i]>>j)&1;
        if (i) prefX[j][i]=prefX[j][i]^prefX[j][i-1];
      }
    }
    long long mx = sum-_xor;
    //cerr << mx << endl;
    int L = 0, R = N - 1;
    for (int i = 0; i < N; ++i) {
      int l = i, r = N - 1, mid;
      while (l < r) {
        mid = (l + r) >> 1;
        long long curr = pref[mid]-(i?pref[i-1]:0);
        for (int j = 0; j < 30; ++j)
          if ((prefX[j][mid]^(i?prefX[j][i-1]:0)))
          curr-=(1<<j);
        //cerr << l << ' ' << r << ' ' << mid << ' ' << curr << endl;
        if (curr == mx) r = mid;
        else l = mid + 1;
      }
      //cerr << i << ' ' << l << endl;
      long long curr = pref[r]-(i?pref[i-1]:0);
      for (int j = 0; j < 30; ++j)
        if ((prefX[j][r]^(i?prefX[j][i-1]:0)))
        curr-=(1<<j);
      if (curr == mx)
        if (r - i < R - L) {
          L = i, R = r;
      }
    }
    cout << L+1 << ' ' << R+1 << endl;
  }
  return 0;
}
