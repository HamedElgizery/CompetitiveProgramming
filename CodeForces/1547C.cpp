#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e3;
int k, n, m;
int a[N], b[N];
int ans[N];

void solve() {
	cin >> k >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	int ap = 0, bp = 0, curr = 0;
	while(ap < n || bp < m) {
		if (ap < n && bp < m) {
			if (a[ap] <= b[bp])
				ans[curr++] = a[ap++];
			else 
				ans[curr++] = b[bp++];
		}
		else {
			if (ap < n)
				ans[curr++] = a[ap++];
			else
				ans[curr++] = b[bp++];
		}
	}
	bool ANS = true;
	for (int i = 0; i < curr; i++) {
		k += !ans[i];
		ANS &= (ans[i] <= k);
	}
	if (ANS) {
		for (int i = 0; i < curr; i++){
			cout << ans[i] << ' '; 
		}
	}
	else {
		cout << -1;
	}
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