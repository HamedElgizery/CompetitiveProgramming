#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 210;
ll dist[mxN][mxN];
int N, M, R;
vector<int> TOVIS;
void solve() {
	for (int i = 0; i < mxN; i++)
		for (int j = 0; j < mxN; j++)
			dist[i][j] = LLONG_MAX;

	cin >> N >> M >> R;
	for (int i = 0; i < R; i++) {
		int tmp;
		cin >> tmp;
		TOVIS.push_back(tmp);
	}
	sort(TOVIS.begin(), TOVIS.end());

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = c;
		dist[b][a] = c;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (dist[i][k] < LLONG_MAX && dist[k][j] < LLONG_MAX)
					dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
			}
		}
	}


	ll ans = LLONG_MAX;

	do {
		ll tmp = 0;
		for (int i = 0; i + 1 < R; i++) {
			tmp += dist[TOVIS[i]][TOVIS[i+1]];
		}
		ans = min(ans, tmp);
	}while(next_permutation(TOVIS.begin(), TOVIS.end()));


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