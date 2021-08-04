#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int dr[] = {1, 1, 1, 0, -1, -1, -1, 0, 0};
int dc[] = {1, 0, -1, -1, -1, 0, 1, 1, 0};

map<pair<int, int>, int> coloredCnt;
int W, H, N;

bool valid(int R, int C) {
	return 1 < R && R < H && 1 < C && C < W;
}

void solve() {
	cin >> H >> W >> N;

	for (int i = 0; i < N; i++) {
		int R, C;
		cin >> R >> C;
		for (int d = 0; d < 9; d++) {
			int nr = R + dr[d];
			int nc = C + dc[d];
			if (valid(nr, nc)) {
				coloredCnt[{nr, nc}]++;
			}
		}
	}

	vector<ll> ans(10, 0);
	ans[0] = max(0, W-2) * 1LL * max(0, H-2);

	for (auto it : coloredCnt) {
		ans[it.second] += 1;
		ans[0]--;
	}

	for (auto it : ans)
		cout << it << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
}