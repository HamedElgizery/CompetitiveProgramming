#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int N;
	string a, b;
	cin >> N >> a >> b;

	for (int i = 1; i < N; i++) {
		if (a[i] > b[i]) {
			cout << "YES\n";
			cout << 1 << ' ' << i + 1 << endl;
			return;
		}
	}
	if (a[0] > b[0] && a[1] == b[1]) {
		cout << "YES\n";
		cout << 1 << ' ' << 2 << endl;
		return;
	}
	else if (a[0] > b[0] && N > 2) {
		cout << "YES\n";
		cout << 2 << ' ' << 3 << endl;
		return;
	}

	cout << "NO\n";
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