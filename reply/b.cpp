#include <bits/stdc++.h>

using namespace std;

struct target {
  int x, y, i, id;

  target() {};
};

int dist(target first, target second) {
  return abs(first.x - second.x) + abs(first.y - second.y);
}

bool better(target first, target second, target curr) {
  int dist1 = dist(curr, first);
  int dist2 = dist(curr, second);
  if (dist1 != dist2)
    return dist1 < dist2;
  if (first.x != second.x) return first.x < second.x;
  return first.y < second.y;
}

int main() {
  freopen("input1.txt", "r", stdin);
  freopen("output1.txt", "w", stdout);
  cin.tie(0)->sync_with_stdio(false);
  int T; cin >> T;
  for (int t = 1; t <= T; ++t) {
    int N, M; cin >> N >> M;
    vector<target> A(M); for (auto &a : A) cin >> a.x >> a.y >> a.i;
    for (int i = 0; i < M; ++i) A[i].id = i;
    int rem = M, last = -1, curr = 0;
    int64_t ans = 0;
    while (rem > 1) {
      A[curr].i--;
      if (!A[curr].i) rem--;
      int best = -1;
      for (int i = 0; i < M; ++i) {
        if (!A[i].i || i == curr || (rem > 2 && i == last)) continue;
        if (!(~best)) {
          best = i;
          continue;
        }
        if (better(A[i], A[best], A[curr])) {
          best = i;
        }
      }
      ans += dist(A[curr], A[best]);
      swap(curr, last);
      curr = best;
    }
    cout << "Case #" << t << ": " << ans;
    if (t < T) cout << '\n';
  }
  return 0;
}
