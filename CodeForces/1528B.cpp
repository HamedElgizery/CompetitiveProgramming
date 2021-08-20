#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 1e6+10, MOD = 998244353;

int divis[mxN];

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i < mxN; i++)
		for (int j = i; j < mxN; j+=i)
			divis[j]++;

	ll dp = 1;
	for (int i = 2; i <= n; i++) {
		dp *= 2;
		dp += divis[i] - divis[i-1];
		dp %= MOD;
	}


	cout << dp;
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
