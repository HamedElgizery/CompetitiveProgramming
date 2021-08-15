#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int ans = 0, S, T;
	cin >> S >> T;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			for (int k = 0; k <= 100; k++) {
				ans += (i * j * k <= T && i + j + k <= S) ;
			}
		}
	}
	cout << ans << endl;
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