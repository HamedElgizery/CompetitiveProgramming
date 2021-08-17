#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int M;
	cin >> M;
	ll A[2][M+1];
	A[0][0] = A[1][0] = 0;

	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> A[i][j];
			A[i][j] += A[i][j-1];
		}
	}

	ll ans = LLONG_MAX;
	for (int i = 1; i <= M; i++) {
		ans = min(ans, max(A[0][M] - A[0][i], A[1][i-1]));
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
	int t;
	cin >> t;
	while(t--) {
		solve();
		cout << '\n';
	}
}