#include <bits/stdc++.h>
using namespace std;

const int mxN = 60 * 300, OO = 0x3f3f3f3f;
int dp[mxN+10];
int main() {
	freopen("darts.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	set<int> st;
	for (int i = 1; i <= 20; i++) {
		for (int j = 1; j <= 3; j++) {
			st.insert(i * j);
		}
	}
	st.insert(25); st.insert(50);

	memset(dp, OO, sizeof dp);
	
	dp[0] = 0;
	for (int i = 1; i <= mxN; i++) {
		for (auto it : st) {
			if (i - it < 0) continue;
			dp[i] = min(dp[i], dp[i - it] + 1);
		}
	}

	int t = 1;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		if (n > mxN) {
			cout << "NO\n";
			continue;
		}
		cout << (dp[n] <= m ? "YES" : "NO") << endl;
	}
}