#include <bits/stdc++.h>

using namespace std;

struct grid {
  int i, s, l;
  int si, sj;
  vector<vector<char>> g;

  grid(int i, int s, int l, vector<vector<char>> &g) {
    this->i = i;
    this->s = s;
    this->l = l;
    this->g = g;
    for (int i = 0; i < s; ++i) {
      for (int j = 0; j < s; ++j) {
        if (g[i][j] == 'I') {
          si = i, sj = j;
          break;
        }
      }
    }
  }

  bool operator<(const grid & right) const {
    return i < right.i;
  }
};

string ans;
string path;
int N, L, P;
char dd[] = {'U', 'D', 'L', 'R'};
int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};
map<array<int, 5>, bool> vis;
vector<grid> A;

bool valid(int i, int j, int s) {
  return 0 <= i && i < s && 0 <= j && j < s;
}

void dfs(int f, int i, int j, int p = 0, int l = 0) {
  if (p > P || vis[{f, i, j, l, p}]) return;
  vis[{f, i, j, l, p}] = 1;
  if (f == N) {
    if (f == N && l >= L) return void(ans = path);
    return;
  }
  

  for (int d = 0; d < 4; ++d) {
    path.push_back(dd[d]);
    int ni = i + di[d], nj = j + dj[d], nf = f;
    if (valid(ni, nj, A[f].s)) {
      if (A[f].g[ni][nj] == 'I') continue;
      if (A[f].g[ni][nj] == 'O') nf++;
      bool mon = A[f].g[ni][nj] == 'M';
      if (mon) A[f].g[ni][nj] = '*';
      dfs(nf, ni, nj, p + 1, l + (int)mon * A[f].l);
      if (mon) A[f].g[ni][nj] = 'M';
    }
    path.pop_back();
    if (!ans.empty()) return;
  }
  vis[{f, i, j, l, p}] = 0;
}

int main() {
  // freopen("input1.txt", "r", stdin);
  // freopen("output1.txt", "w", stdout);
  cin.tie(0)->sync_with_stdio(false);
  int T; cin >> T;
  for (int t = 1; t <= T; ++t) {
    vis.clear();
    A.clear();
    cin >> N >> L >> P;
    for (int j = 0; j < N; ++j) {
      int i, s, l; cin >> i >> s >> l;
      vector<vector<char>> GRID(s, vector<char>(s));
      for (auto &g : GRID)
        for (auto &it : g)
          cin >> it;
      grid g(i, s, l, GRID);
      A.push_back(g);
    }
    sort(A.begin(), A.end());
    cout << "Case #" << t << ": ";
    dfs(0, A[0].si, A[0].sj); 
    cout << ans; 
    ans.clear();
    path.clear();
    if (t > T) cout << '\n';
  }
  return 0;
}
