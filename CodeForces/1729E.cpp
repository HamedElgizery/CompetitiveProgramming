#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  vector<pair<long long, long long>> resp;
  for (int i = 1; i <= 25; ++i) {
    long long res1, res2;
    cout << "? " << i << ' ' << i+1 << endl;
    cin >> res1;
    cout << "? " << i+1 << ' ' << i << endl;
    cin >> res2;
    resp.push_back(make_pair(res1, res2));
    if (res1==-1) {
      cout << "! " << i << endl;
      return 0;
    }
  }
  for (auto it : resp) {
    if (it.first-it.second) {
       cout << "! " << it.first + it.second << endl; 
       return 0;
    }
  }
  cout << "! " << resp.front().first + resp.front().second << endl;
  return 0;
}
