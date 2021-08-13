#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 2e3+10, OO = 0x3f3f3f3f;
ll A[mxN], N, P, Q;
int dp[mxN][mxN];

bool ok(ll mid) {
	memset(dp, OO, sizeof dp);
	dp[0][0] = 0;

	for (int i = 0; i < N; i++) {
		int nxt_p = lower_bound(A, A+N, A[i] + mid) - A;
		int nxt_q = lower_bound(A, A+N, A[i] + 2 * mid) - A;
		for (int np = 0; np <= P; np++) {
			dp[nxt_p][np+1] = min(dp[nxt_p][np+1], dp[i][np]);
			dp[nxt_q][np] = min(dp[nxt_q][np], dp[i][np]+1);
		}
	}

	for (int i = 0; i <= P; i++) if (dp[N][i] <= Q) return 1;
	return 0;
}

void solve() {
	cin >> N >> P >> Q;
	P = min(P, N);
	Q = min(Q, N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A, A+N);

	ll l = 1, r = 1e10, mid;
	while(l < r) {
		mid = (l+r) >> 1;
		if (ok(mid)) r = mid;
		else l = mid+1;
	}
	cout << r << endl;
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