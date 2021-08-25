#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("beautiful.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		int n;
		long long k, a[26];
		cin >> n >> k;
		string s;
		cin >> s;
		for (auto &I : a)
			cin >> I;
		long long cnt = 0;
		for(int i = 0; i < n; ++i)
			cnt += a[s[i] - 'a'];
		if(cnt > k)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}