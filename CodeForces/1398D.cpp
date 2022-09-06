#include <bits/stdc++.h>

using namespace std;


void solve() {
	int SZ[3];

	vector<vector<int>> sticks(3);

	for (int i = 0; i < 3; i++)
		cin >> SZ[i], sticks[i].assign(SZ[i]+1, 0);

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < SZ[i]; j++)
			cin >> sticks[i][j];

	for (int i = 0; i < 3; i++)
		sort(sticks[i].begin(), sticks[i].end());

	vector<vector<vector<int>>> dp(SZ[0]+1, vector<vector<int>>(SZ[1]+1, vector<int>(SZ[2]+1, 0)));

	for (int i = 0; i <= SZ[0]; i++)
		for (int j = 0; j <= SZ[1]; j++)
			for (int k = 0; k <= SZ[2]; k++) {
				dp[i][j][k] = max({
					dp[i][j][k],
					sticks[0][i] * sticks[1][j] + (i&&j?dp[i-1][j-1][k]:0),
					sticks[0][i] * sticks[2][k] + (i&&k?dp[i-1][j][k-1]:0),
					sticks[1][j] * sticks[2][k] + (j&&k?dp[i][j-1][k-1]:0)
				});
			}

	cout << dp[SZ[0]][SZ[1]][SZ[2]];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}