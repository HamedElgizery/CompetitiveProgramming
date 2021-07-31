#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 201;
int MN[10], C[10][10], A[mxN][mxN], H, W;

int dfs(int num, int msk) {
	if (num == 1)
		return 0;
	int ret = INT_MAX;
	for (int i = 0; i <= 9; i++) {
		if ((1<<i) & msk)
			continue;
		ret = min(ret, C[num][i] + dfs(i, msk|(1<<i)));
	}
	return ret;
}


void solve() {
	cin >> H >> W;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> C[i][j];
		}
	}

	for (int i = 0; i < 10; i++) {
		MN[i] = dfs(i, 0);
	}

	int ans = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> A[i][j];
			if (~A[i][j])
				ans += MN[A[i][j]];
		}
	}
	cout << ans;
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