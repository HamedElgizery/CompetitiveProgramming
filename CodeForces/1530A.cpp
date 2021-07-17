#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	string s;
	cin >> s;
	char ans = '0';
	for (auto it : s) 
		ans = max(ans, it);
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