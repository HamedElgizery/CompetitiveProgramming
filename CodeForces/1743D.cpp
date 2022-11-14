#include <bits/stdc++.h>

using namespace std;
template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

bool better(string &a, string &b) {
  if (a.size() > b.size()) 
    b = string(a.size()-b.size(), '0') + b;
  if (a.size() < b.size())
    a = string(b.size()-a.size(), '0') + a;
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] > b[i]) return 1;
    if (a[i] < b[i]) return 0;
  }
  return 0;
}

string operator | (const string &a, const string &b) {
  string ret = string(max(a.size(), b.size()), '0');
  for (int i = 0; i < a.size(); ++i)
    if (a[i] == '1') ret[ret.size()-a.size()+i] = '1';
  for (int i = 0; i < b.size(); ++i)
    if (b[i] == '1') ret[ret.size()-b.size()+i] = '1';
  return ret;
}
string remZleading(string &A) {
  int idx = A.find('1');
  if (idx == string::npos) {
  	return "0";
  }
  return A.substr(idx, A.size() - idx);
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int N; cin >> N;
  string S; cin >> S;
  string ans = S;
  int pos1 = S.find("1");
  if (pos1 != string::npos) {
    int pos2 = S.find("0", pos1);
    if (pos2 != string::npos) {
        int curr = pos1;
        int shift = 0;
    	while (true) {
          if (curr >= N || (curr > pos2)) break;
          string nw = S | S.substr(pos1, N - pos1 - shift);
          if (better(nw, ans)) ans = nw;
          curr++;
          shift++;
      }
    }
  }
  cout << remZleading(ans);
  return 0;
}
