#include <bits/stdc++.h>

using namespace std;

template<typename T> T umax(T& a, T& b) {return a = max(a, b);}
template<typename T> T umin(T& a, T& b) {return a = min(a, b);}

struct point {
  int y, x;
  point() {}
  point(int y, int x) : y(y), x(x) {}

  bool operator ==(const point & right) const {
    return x == right.x && y == right.y;
  }
  bool operator <(const point & right) const {
    if (x != right.x) return x < right.x;
    return y < right.y;
  }
};

map<int, set<int>> obstX, obstY;
map<point, bool> vis;
int H, W, N;
point st, en;

point UP(point p) {
  auto it = obstX[p.x].upper_bound(p.y);
  if (it == obstX[p.x].begin()) return point(-1, -1);
  return point(*prev(it) + 1, p.x);
}

point DOWN(point p) {
  auto it = obstX[p.x].upper_bound(p.y);
  if (it == obstX[p.x].end()) return point(-1, -1);
  return point(*it - 1, p.x);
}

point RIGHT(point p) {
  auto it = obstY[p.y].upper_bound(p.x);
  if (it == obstY[p.y].end()) return point(-1, -1);
  return point(p.y, *it - 1);
}

point LEFT(point p) {
  auto it = obstY[p.y].upper_bound(p.x);
  if (it == obstY[p.y].begin()) return point(-1, -1);
  return point(p.y, *prev(it) + 1);
}

int bfs(point st) {
  queue<pair<point, int>> q;
  q.push({st, 0});
  vis[st] = 1;
  while (!q.empty()) {
    point curr = q.front().first;
    int dist = q.front().second;
    q.pop();
    if (curr == en) return dist;
    point up = UP(curr);
    if (~up.x && !vis[up])
    q.push({up, dist + 1});
    point down = DOWN(curr);
    if (~down.x && !vis[down])
    q.push({down, dist + 1});
    point right = RIGHT(curr);
    if (~right.x && !vis[right])
    q.push({right, dist + 1});
    point left = LEFT(curr);
    if (~left.x && !vis[left])
    q.push({left, dist + 1});
    vis[up] = vis[down] = vis[right] = vis[left] = 1;
  }
  return -1;
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  cin >> H >> W >> N;
  cin >> st.y >> st.x >> en.y >> en.x;
  for (int i = 0; i < N; ++i) {
    int y, x; cin >> y >> x;
    obstY[y].insert(x);
    obstX[x].insert(y);
  }
  cout << bfs(st);
  return 0;
}
