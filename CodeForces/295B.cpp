#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 501;
ll tmpa[N][N], a[N][N], ans[N], order[N], n;

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++)
			cin >> tmpa[i][j];

	for (int i = 1; i <= n; i++)
		cin >> order[i];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] = tmpa[order[i]][order[j]];
		}
	}

	for (int k = n; k ; k--) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
			}
		}
		for (int i = k; i <= n; i++)
			for (int j = k; j <= n; j++)
				ans[k] += a[i][j];
	}

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
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