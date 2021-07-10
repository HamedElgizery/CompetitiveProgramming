#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
string s;
int n;

void solve() {
	cin >> s;
	n = s.size();

	int st = 0;
	while(st < n && s[st] != 'a')
		st++;
	if (st == n) {
		cout << "NO";
		return;
	}
	bool ans = 1;
	int l = st-1, r = st+1;
	char curr = 'b';
	while((l >= 0 || r < n) && ans) {
		bool tmp = false;
		if (l >= 0) {
			if (s[l] == curr)
				l--, tmp = !tmp;
		}
		if (r < n) {
			if (s[r] == curr)
				r++, tmp = !tmp;
		}
		curr++;
		ans &= tmp;
	}

	cout << (ans ? "YES" : "NO");
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