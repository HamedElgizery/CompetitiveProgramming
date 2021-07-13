#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 301;
int n, k;
ll adj[N][N], sum;

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> adj[i][j], sum += adj[i][j];

	sum/=2;
	cin >> k;
	while(k--) {
		int u, v, c;
		cin >> u >> v >> c; 
		for (int i = 1; i <= n; i++) {
			for (int j = i+1; j <= n; j++) {
				if (adj[i][j] > adj[i][u] + c + adj[v][j])
					sum -= adj[i][j], adj[i][j] = adj[j][i] = adj[i][u] + c + adj[v][j], sum += adj[i][j];
				if (adj[i][j] > adj[i][v] + c + adj[u][j])
					sum -= adj[i][j], adj[i][j] = adj[j][i] = adj[i][v] + c + adj[u][j], sum += adj[i][j];
			}
		}
		cout << sum << ' ';
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