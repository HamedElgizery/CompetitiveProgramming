#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T b) {return a = max(a, b);}
template<typename T> T umin(T& a, T b) {return a = min(a, b);}

const long long mxSz = 1e5;

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int M; cin >> M;
  vector<int> seq;
  vector<pair<int, int>> pro(M);
  for (auto &it : pro) {
    int t; cin >> t;
    if (t == 1) {
      int x; cin >> x;
      it.first = x;
      it.second = -1;
    }
    else {
      int l, c; cin >> l >> c;
      it.first = l, it.second = c;
    }
  }
  int N; cin >> N;
  vector<pair<long long, int>> que(N);
  {
    int i = 0;
    for (auto &it : que) {
      cin >> it.first;
      --it.first;
      it.second = i++;
    }
    sort(que.begin(), que.end());
  }
  vector<int> ans(N);
  int i = 0;
  long long currSz = 0;
  for (auto it : pro) {
    if (!~it.second) {
      currSz++;
      if (seq.size() < mxSz) seq.push_back(it.first);
      while (i < N && que[i].first < currSz) {
        ans[que[i].second] = it.first;
        ++i;
      }
    }
    else {
      int l = it.first, c = it.second;
      int j = 0;
      while (i < N && currSz + l * c > que[i].first) {
        que[i].first-=currSz;
        ans[que[i].second] = seq[que[i].first%l];
        i++;
      }
      currSz += l * c;
      while (seq.size() < min(currSz, mxSz)) {
        seq.push_back(seq[j]);
        (j+=1)%=l;
      }
    }
  }
  for (auto it : ans) cout << it << ' ';
  return 0;
}
