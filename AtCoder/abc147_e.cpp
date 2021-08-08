#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 85, mxD = 160*80;

bool dp[mxD*2+10][mxN][mxN];
int AB[2][mxN][mxN], GRID[mxN][mxN];

void solve() {
	int H, W;
	cin >> H >> W;

	for (int k = 0; k < 2; k++)
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
				cin >> AB[k][i][j];
		
	for (int i = 0; i < H; ++i)
		for (int j = 0; j < W; ++j)
			GRID[i][j] = abs(AB[0][i][j] - AB[1][i][j]);
	
	dp[GRID[0][0]][0][0] = 1;

	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (!i && !j)
				continue;
			for (int k = 0; k < mxD; ++k) {
				int need1 = abs(GRID[i][j] - k);
				int need2 = abs(GRID[i][j] + k);
				if (i)
					dp[k][i][j] |= (dp[need1][i-1][j] | dp[need2][i-1][j]);
				if (j)
					dp[k][i][j] |= (dp[need1][i][j-1] | dp[need2][i][j-1]);
			}
		}
	}

	for (int i = 0; i < mxD; ++i) {
		if (dp[i][H-1][W-1]) {
			cout << i;
			return;
		}
	}
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