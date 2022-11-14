#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

string con(int a) {
  string A = to_string(a);
  string ret;
  for (auto it : A) {
    if (it == '7' || it == '4') ret.push_back(it);
  }
  return ret;
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int a, b; cin >> a >> b;
  string B = to_string(b);
  a++;
  while (con(a) != B) {
    a++;
  }
  cout << a;
  return 0;
}
