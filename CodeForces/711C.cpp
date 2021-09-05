#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll OO = 2e18;

void solve() {
	int N, M, K;
	cin >> N >> M >> K;

	vector<int> colors(N);
	vector<vector<ll>> P(N, vector<ll>(M));
	vector<vector<vector<ll>>> dp(N, vector<vector<ll>>(K+1, vector<ll>(M+1, OO)));

	for (auto& c : colors) cin >> c;
	for (auto& p : P)
		for (auto& c : p) 
			cin >> c;

	if (colors[0] == 0)
		for (int i = 0; i < M; i++)
			dp[0][1][i+1] = P[0][i];
	else
		dp[0][1][colors[0]] = 0;

	for (int i = 1; i < N; i++) {
		for (int j = 1; j <= K; j++) {
			for (int c = 1; c <= M; c++) {
				if (c == colors[i] || !colors[i]) {
					for (int cc = 1; cc <= M; cc++) {
						dp[i][j][c] = min(dp[i][j][c], dp[i-1][j-(cc!=c)][cc] + P[i][c-1] * (c != colors[i]));
					}
				}
			}
			
		}
	}

	ll ans = OO;
	for (int i = 1; i <= M; i++)
		ans = min(ans, dp[N-1][K][i]);
	if (ans >= OO) ans = -1;

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