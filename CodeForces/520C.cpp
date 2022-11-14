#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

const string c = "ACGT";
const int MOD = 1e9 + 7;

long long FP(long long x, long long y) {
  long long ret = 1;
  while (y) {
    if (y&1) (ret *= x) %= MOD;
    (x*=x)%=MOD;
    y>>=1;
  }
  return ret;
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int N; cin >> N;
  string S; cin >> S;
  vector<int> freq;
  for (auto it : c)
    freq.push_back(count(S.begin(), S.end(), it));
  sort(freq.begin(), freq.end());
  int equ = count(freq.begin(), freq.end(), freq.back());
  cout << FP(equ, N);
  return 0;
}
