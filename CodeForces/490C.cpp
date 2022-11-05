#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  string S; cin >> S;
  int N = S.size();
  int a, b; cin >> a >> b;
  int left = 0, right = 0;
  vector<int> tens(N + 1, 1);
  for (int i = 1; i <= tens.size(); ++i) tens[i]=(tens[i-1]*10)%b;
  for (int i = N-1; ~i; --i)
    (right += (S[i]-'0')*tens[N-i-1])%=b;
  for (int i = 0; i+1 < N; ++i) {
    (left*=10)%=a;
    (left+=S[i]-'0')%=a;
    (right-=tens[N-i-1]*(S[i]-'0'))%=b;
    if (!left && !right && S[i+1]!='0') {
      cout << "YES\n";
      cout << S.substr(0, i+1) << '\n';
      cout << S.substr(i+1, N - i - 1);
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
