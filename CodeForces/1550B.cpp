#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n, a, b;
string s;

void solve() {
	cin >> n >> a >> b >> s;
	ll ans;
	if (b >= 0) {
		ans = b * n + a * n;
	}else {
		int freq[2] = {0, 0};
		bool curr = (s[0] == '1');
		for (int i = 0; i < n; i++) {
			if ((s[i]-'0') != curr) {
				freq[curr]++;
				curr = !curr;
			}
		}
		freq[curr]++;
		if (!freq[0] || !freq[1]) {
			ans = a*n + b;
		}
		else {
			ans = (min(freq[0], freq[1])+1) * (b) + a*n;
		}
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